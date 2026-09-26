class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>>q;
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,(vector<int>(m,0)));
        vector<vector<int>> ans(n,(vector<int>(m,0)));
        vector<vector<int>> dir= {{0,1},{0,-1},{-1,0},{1,0}};

        // Feed queue with all 0 fields
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {
                    q.push({i,j,0});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it[0],col=it[1],cnt=it[2];

            ans[row][col]=cnt;
           
            for(auto d:dir){
                int nrow=row+d[0];
                int ncol=col+d[1];
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && vis[nrow][ncol]!=1){
                    // We push this valid field into queue with cnt++ 
                    q.push({nrow,ncol,cnt+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
    }
};