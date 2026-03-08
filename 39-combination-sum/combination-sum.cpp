class Solution {
public:
    set<vector<int>>st;
    int n;
    void fun(vector<int>&cand,int target,int idx,vector<int>&curr){
        if(target==0){
            // sort(curr.begin(),curr.end());
            st.insert(curr);
            return;
        }
        
        for(int i=idx;i<n;i++){
            if(cand[i]>target) continue;
            curr.push_back(cand[i]);
            fun(cand,target-cand[i],i,curr);
            curr.pop_back();            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>curr;
        // sort(candidates.begin(),candidates.end());
        // sort()
        fun(candidates,target,0,curr);
        vector<vector<int>>ans(st.begin(),st.end());

        return ans;
    }
};