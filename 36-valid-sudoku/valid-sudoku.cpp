class Solution {
public:

    bool fun(vector<vector<char>>& board,int row,int col){
        unordered_set<int>st;
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // brute

        for(int i=0;i<board.size();i++){
            unordered_set<int>row;
            unordered_set<int>column;

            for(int j=0;j<board[0].size();j++){
                // column
                
                if(board[i][j]!='.'){
                int temp=board[i][j]-'0';
                if(column.count(temp)) return false;
                column.insert(temp);
                }
                
                // row
                if(board[j][i]!='.'){
                int temp2=board[j][i]-'0';
                if(row.count(temp2)) return false;
                row.insert(temp2);
                }

                if((i%3==0) && (j%3==0)){
                    if(!fun(board,i,j)) return false;
                }
            }
        }

        // for(int )

        return true;
    }
};