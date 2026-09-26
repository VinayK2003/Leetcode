class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 ||j==0 ||i==n-1|| j==m-1){
                    if(!vis[i][j] && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first, col= q.front().second;
            q.pop();
            for(auto d:dir){
                int nrow=row+d[0];
                int ncol=col+d[1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && vis[i][j]==0)
                board[i][j]='X';
            }
        }
    }
};