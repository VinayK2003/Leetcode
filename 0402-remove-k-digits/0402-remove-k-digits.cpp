class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(num.size()==k) return "0";
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }   
            st.push(num[i]);
        }
        while(k>0){
            st.pop();k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size()>1 && ans[0]=='0') ans.erase(ans.begin());
        return ans;

    }
};