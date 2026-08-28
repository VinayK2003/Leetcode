class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26]={0};
        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }

        priority_queue<int>pq;

        for(auto i:arr){
            if(i>0){
                pq.push(i);
            }
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;

            for(int i=1;i<=n+1;i++){
                    if(!pq.empty()){
                        int x=pq.top();
                        pq.pop();
                        x--;
                        temp.push_back(x);
                    }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};