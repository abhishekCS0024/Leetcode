class Solution {
public:
    int n,m;
    bool fun(vector<vector<char>>& board, string word,int i,int j,int index){
        
        if(word.size()==index){
            return true;
        }
        if(i<0||i>=n || j<0 || j>=m || board[i][j]!=word[index]) return false;

        

        char temp=board[i][j];

        board[i][j]='#';

        bool found= fun(board,word,i-1,j,index+1)||fun(board,word,i+1,j,index+1)||fun(board,word,i,j+1,index+1)||fun(board,word,i,j-1,index+1);

        board[i][j]=temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(),m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(fun(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};