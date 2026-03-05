class Solution {
public:

    int ans=0;
    int cnt,n,m;
    void fun(vector<vector<int>>& grid,int i,int j,int step){
        // if(step==cnt && grid[i][j]==2){
        //     ans++;
        //     return ;
        // }
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1){
            return ;
        }
        if(grid[i][j] == 2){
            if(step == cnt) ans++;
            return;
        }

        int temp=grid[i][j];

        grid[i][j]=-1;

        fun(grid,i-1,j,step+1);
        fun(grid,i+1,j,step+1);
        fun(grid,i,j-1,step+1);
        fun(grid,i,j+1,step+1);

        grid[i][j]=temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        cnt=1;
        n=grid.size(), m=grid[0].size();
        int s1,s2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) cnt++;
                if(grid[i][j]==1){
                    s1=i,s2=j;
                }
            }
        }

        fun(grid,s1,s2,0);

        return ans;
    }
};