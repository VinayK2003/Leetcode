class Solution {
public:

// So for every sudoku board there must be 17 filled cells
// That means 81-17= 64 cells are empty

// We try 9 combinations for those 64 empty cells and 
//For every combination we check if its valid or not

// TC:- O((9^64)*9)
// SC:- Recursion Depth= O(64)
    bool helper(vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // First we find empty cells and try every number and check if its valid or not 
                if(board[i][j]=='.'){
                    for(int c='1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j]=c;
                            //Need to return true if the new board is solved
                            if(helper(board)) return true;;
                            board[i][j]='.';
                        }
                    }
                    //If every number cannot fit into that cell, then  we backtrack and try another number in the previous cell
                    return false;
                }
            }
        }
        //We reach here when there are no empty cells left 
        // Board is solved
        return true;
    }


    bool isValid(char c,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};