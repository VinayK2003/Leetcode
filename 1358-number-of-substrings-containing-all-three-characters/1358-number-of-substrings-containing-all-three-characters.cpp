class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int arr[3]={0};
        int i=0;
        for(int j=0;j<s.size();j++){
            arr[s[j]-'a']++;
            while(arr[0]>0 && arr[1]>0 && arr[2]>0){
                cnt+=s.size()-j;
                arr[s[i]-'a']--;
                i++;
            }
        }
        return cnt;
    }
};