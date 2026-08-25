class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        int require[128]={0};
        for(char c: t){
            require[c-'A']++;
        }
        int window[128]={0};
        int cnt=0;
        int i=0,j=0;
        int ans=INT_MAX;
        int ind;
        while(j<s.size()){
            window[s[j]-'A']++;
            if(window[s[j]-'A'] <=require[s[j]-'A'] ) cnt++;
            while(cnt==t.size()){
                if(j-i+1<ans){
                    ans=j-i+1;
                    ind=i;
                }
                window[s[i]-'A']--;
                if(window[s[i]-'A'] < require[s[i]-'A']) cnt--;

                i++;
            }
            j++;
        }

        if(ans==INT_MAX) return "";

        return s.substr(ind,ans);
    }
};