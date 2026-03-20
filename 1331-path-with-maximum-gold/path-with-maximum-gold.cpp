class Solution {
public:

    int maxi=0;

    void explore(vector<vector<int>>& grid,int i,int j,int &ans){
        if(i<0 || j<0 || j>=grid[0].size() || i>=grid.size() || grid[i][j]==0){
            maxi=max(maxi,ans);
            return ;
        }
        ans+=grid[i][j];
        int temp=grid[i][j];
        grid[i][j]=0;

        explore(grid,i-1,j,ans);
        explore(grid,i+1,j,ans);
        explore(grid,i,j-1,ans);
        explore(grid,i,j+1,ans);

        grid[i][j]=temp;
        ans-=temp;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    explore(grid,i,j,ans);
                }
            }
        }

        return maxi;
    }
};