class Solution {
public:
    int cnt=0;
    void fun(vector<int>& nums, int target,int curr,int i){
        if(i==nums.size()){
            if(curr==target) cnt++;
            return;
        }

        fun(nums,target,curr+nums[i],i+1);
        fun(nums,target,curr-nums[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        fun(nums,target,0,0);

        return cnt;
    }
};