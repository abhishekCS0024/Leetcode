class Solution {
public:

    int fun(vector<int>& nums, int target,int total,vector<vector<int>>&dp,int i,int sum){
        if(i==nums.size()){
            if(target==sum){
                return 1;
            }
            return 0;
        }

        if(dp[sum+total][i]!=-1) return dp[sum+total][i];
        int plus=fun(nums,target,total,dp,i+1,sum+nums[i]);
        int minus=fun(nums,target,total,dp,i+1,sum-nums[i]);

        return dp[sum+total][i]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        vector<vector<int>>dp((total*2)+1,vector<int>(n+1,-1));

        return fun(nums,target,total,dp,0,0);
    }
};