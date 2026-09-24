class Solution {
public:

    void dfs( vector<int>adj[],int i, vector<int>& vis,int& node,int& totaldegree){
        vis[i]=1;
        node++;
        totaldegree+=adj[i].size();
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(adj,it,vis,node,totaldegree);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int node=0;
                int totaldegree=0;
                dfs(adj,i,vis,node,totaldegree);
                if(totaldegree==node*(node-1)) cnt++;                
            }
        }
        return cnt;
    }
};