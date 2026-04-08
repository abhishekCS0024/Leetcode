class Solution {
public:

    vector<vector<int>>dp;
    int fun(int n,int m,string s,string t){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        int include=0,exclude=0;

        if(s[n-1]==t[m-1]){
            include=1+fun(n-1,m-1,s,t);
        }
        exclude=max(fun(n,m-1,s,t),fun(n-1,m,s,t));

        return dp[n][m]=max(include,exclude);
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        dp.resize(n+1,(vector<int>(m+1,-1)));
        if(fun(n,m,s,t)==n)return true;
        return false;
    }
};