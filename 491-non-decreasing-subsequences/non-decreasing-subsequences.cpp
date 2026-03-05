class Solution {
public:
    vector<vector<int>> result;
    int n;

    void fun(vector<int>& nums, int start, vector<int> &curr){

        if(curr.size()>=2){
            result.push_back(curr);
            // return;
        }

        unordered_set<int>st;

        for(int i=start;i<n;i++){
            if(st.count(nums[i])) continue;
            if(curr.empty() || curr.back()<=nums[i]){
            st.insert(nums[i]);
            curr.push_back(nums[i]);
            fun(nums,i+1,curr);
            curr.pop_back();
            
        }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int>curr;
        fun(nums,0,curr);
        return result;
    }
};


// // Pure Recursion
// class Solution {
// public:
//     set<vector<int>> result;
//     int n;

//     void fun(vector<int>& nums, int i, vector<int> curr){

//         if(curr.size()>=2 && i==n){
//             result.insert(curr);
//             return;
//         }

//         if(i>=n) return;

//         if(curr.empty() || curr.back()<=nums[i]){
//             curr.push_back(nums[i]);
//             fun(nums,i+1,curr);
//             curr.pop_back();
//         }

//         fun(nums,i+1,curr);
//     }

//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         n=nums.size();
//         fun(nums,0,{});
//         return vector<vector<int>>(result.begin(),result.end());
//     }
// };