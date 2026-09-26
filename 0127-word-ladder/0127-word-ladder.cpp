class Solution {
public:

    // Here pass set by reference, becoz we are calling this a lot of time
    // so we dont this to make unnecessary copies of it
    bool check(unordered_set<string>&s, string a){
        if(s.find(a)!=s.end()) return true;
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string st=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(st==endWord) return cnt;
            for(int i=0;i<st.size();i++){
                string a=st;
                for(char j='a'; j<='z';j++){
                    a[i]=j;
                    if(check(s,a)){
                        s.erase(a);
                        q.push({a,cnt+1});
                    }
                }
            }
        }
        return 0;

    }
};