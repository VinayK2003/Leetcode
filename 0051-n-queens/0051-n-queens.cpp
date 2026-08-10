class Solution {
public:

    bool isSafe(int col, int row,vector<string>& path,int n){
        int drow=row, dcol=col;

        //downward traverse
        while(col>=0){
            if(path[row][col]=='Q') return false;
            col--;
        }
        col=dcol;

        // Upward Diagonal Traverse
        while(col>=0 && row>=0){
            if(path[row][col]=='Q') return false;
            col--; row--;
        }
        col=dcol;
        row=drow;

        //Downward Diagonal Traverse
        while(col>=0 && row<n){
            if(path[row][col]=='Q') return false;
            col--; row++;
        }
        col=dcol;
        row=drow;

        return true;
    }

    void helper (int col, int n,vector<vector<string>>& ans,vector<string>& path){
         if (col == n) {
            ans.push_back(path);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(col,i,path,n)){
                path[i][col]='Q';
                helper(col+1,n,ans,path);
                path[i][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n,string(n,'.'));
        helper(0,n,ans,path);

        return ans;
    }
};