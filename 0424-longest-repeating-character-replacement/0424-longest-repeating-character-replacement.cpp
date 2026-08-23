class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq=0,n=s.size(),i=0,j=0;
        int maxlen=0,arr[26]={0};
        while(j<n){
            arr[s[j]-'A']++;
            maxfreq=max(maxfreq, arr[s[j]-'A']);

        // Basically the number of chars that need replacement is equl to
        // window size - max freq char
            while((j-i+1 )- maxfreq >k){
                arr[s[i]-'A']--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};