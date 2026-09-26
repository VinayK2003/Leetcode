class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        int n=image.size(),m=image[0].size();
        vector<int>adj[n];
        // Using BFS 
        queue<pair<int,int>>q;
        vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        q.push({sr,sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            image[row][col]=color;
            q.pop();
            for(int i=0;i<dir.size();i++){
                int nrow=row+dir[i][0];
                int ncol=col+dir[i][1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && vis[nrow][ncol]!=1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
         
    }
};