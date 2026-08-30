class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<boxTypes.size();i++){
            pq.push({boxTypes[i][1],boxTypes[i][0]});
        }
        int ans=0,cntbox=0;
        while(cntbox<truckSize && !pq.empty()){
                if(cntbox+pq.top().second<=truckSize){
                    ans+=pq.top().first* pq.top().second;
                    cntbox+=pq.top().second;
                    pq.pop();
                }else{
                    int quantity= truckSize-cntbox;
                    ans+= quantity*pq.top().first;
                    cntbox+=quantity;
                }
        }
        return ans;
    }
};