class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int j=k-1, i=cardPoints.size()-1;
        int maxi=sum;
        while(j>=0){
            sum-=cardPoints[j];
            j--;
            sum+=cardPoints[i];
            i--;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};