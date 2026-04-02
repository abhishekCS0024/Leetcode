class Solution {
public:

    vector<vector<int>>dp;
    int fun(string &s1, string &s2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        
        if(dp[n][m]!=-1)return dp[n][m];
        int include=0,exclude=0;
        if(s1[n-1]==s2[m-1]){
            include=1+fun(s1,s2,n-1,m-1);
        }
        exclude=max(fun(s1,s2,n,m-1),fun(s1,s2,n-1,m));
        
        return dp[n][m]=max(include,exclude);
    }

    int minInsertions(string s) {
        int n=s.size();
        string s1=s, s2=s;
        reverse(s2.begin(),s2.end());
        dp.resize(n+1,vector<int>(n+1,-1));
        return (n-fun(s1,s2,n,n));
    }
};


// mbadm
// mdabm