class Solution {
public:

//  TC:- O(N*M*4^L)   L= length of word
//  SC:- O(L)  // Recursion stack

    bool search(vector<vector<char>>& board, string word,int i,int j,int k){
        int n=board.size();
        int m=board[0].size();
        if(k==word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k]) return false;

        // we should not visit the same cell again
        char ch=word[k];
        board[i][j]='#';

       bool opt1= search(board,word,i+1,j,k+1);
       bool opt2= search(board,word,i-1,j,k+1);
       bool opt3= search(board,word,i,j+1,k+1);
       bool opt4= search(board,word,i,j-1,k+1);

       board[i][j]=ch; 
       return opt1 ||opt2 || opt3 || opt4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(search(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};