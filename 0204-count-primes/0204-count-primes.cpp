class Solution {
public:
    int countPrimes(int n) {
        vector<bool>seen(n,false);
        int ans=0;
        for(int i=2;i<n;i++){
            if(seen[i]) continue;
            ans++;
            for(long long int j=(long)i*i;j<n;j+=i){
                seen[j]=true;
            }
        }
        return ans;
            
        }
    
};