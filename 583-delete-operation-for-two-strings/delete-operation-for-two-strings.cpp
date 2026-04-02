class Solution {
public:

    vector<vector<int>>dp;
    int fun(string word1, string word2,int n,int m){
        if(n==0 || m==0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];
        int include=0,exclude=0;
        if(word1[n-1]==word2[m-1]){
            include=1+fun(word1,word2,n-1,m-1);
        }
        else{
            exclude=max(fun(word1,word2,n-1,m),fun(word1,word2,n,m-1));
        }

        return dp[n][m]=max(include,exclude);
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));

        int temp=fun(word1,word2,n,m);
        return (n-temp)+(m-temp);

    }
};

// if the matching subsequence is less than the word2 we need to add