class Solution {
public:
    set<vector<int>> result;
    int n;

    void fun(vector<int>& nums, int i, vector<int> curr){

        if(curr.size()>=2 && i==n){
            result.insert(curr);
            return;
        }

        if(i>=n) return;

        if(curr.empty() || curr.back()<=nums[i]){
            curr.push_back(nums[i]);
            fun(nums,i+1,curr);
            curr.pop_back();
        }

        fun(nums,i+1,curr);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        fun(nums,0,{});
        return vector<vector<int>>(result.begin(),result.end());
    }
};