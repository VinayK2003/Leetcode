class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        int i=0,j=0,n=s.length(),maxlen=0;
        while(j<n){
            while(hash[s[j]]==1) {
                hash[s[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            hash[s[j]]=1;
            j++;    
        }
        return maxlen;
    }
};