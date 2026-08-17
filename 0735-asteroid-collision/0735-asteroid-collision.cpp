class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x: asteroids){
            while(!st.empty() && st.top()>0 && x<0){
                // incoming is bigger
                if(st.top()<-x){
                    st.pop();
                }

                //if incomign is of eq size
                else if( st.top()==-x){
                    st.pop();
                    x=0; // Here we are not touching the given vector, we are only touching the copy variable
                }

                //incoming is smaller
                else{
                    x=0;
                }
            }
            if(x!=0) st.push(x);
        }
        // we have marked all the asteroids that would get destroyed
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};