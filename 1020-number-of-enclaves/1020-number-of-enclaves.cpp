class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 ||j==0 || j== m-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first, col= q.front().second;
            q.pop();
            for(auto d :dir){
                int nrow=row+d[0];
                int ncol=col+d[1];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};