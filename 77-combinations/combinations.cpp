class Solution {
public:
    vector<vector<int>>result;
    void fun(int n,int k,int idx,vector<int>&curr){
        if(k==0){
            result.push_back(curr);
            return ;
        }

        if(idx>(n)) return;

        for(int i=idx;i<=n;i++){
            curr.push_back(i);
            fun(n,k-1,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        fun(n,k,1,curr);
        return result;
    }
};