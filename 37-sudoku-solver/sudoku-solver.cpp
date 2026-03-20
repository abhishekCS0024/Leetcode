class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char d){

        for(int i=0;i<9;i++){
            if(board[i][col]==d) return false;
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==d) return false;
        }
        int x=(row/3)*3,y=(col/3)*3;
        for(int i=x;i<=x+2;i++){
            for(int j=y;j<=y+2;j++){
                if(board[i][j]==d) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.') continue;
                char k='1';
                for(int c=0;c<9;c++){
                    if(isValid(board,i,j,k+c)){
                        board[i][j]=k+c;
                        if(solve(board)) return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};