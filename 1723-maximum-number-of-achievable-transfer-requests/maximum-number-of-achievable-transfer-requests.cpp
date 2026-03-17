class Solution {
public:
    int ans;
    void  fun(vector<vector<int>>& req,int i,vector<int>&temp,int cnt){
        if(req.size()==i){
            for(int i=0;i<temp.size();i++){
                if(temp[i]!=0){
                    return ;
                }
            }
            ans=max(ans,cnt);
            return;
            // return cnt;
        }

        // for(int j=i;j<req.size();j++){
            temp[req[i][0]]--;
            temp[req[i][1]]++;
            fun(req,i+1,temp,cnt+1);
            temp[req[i][0]]++;
            temp[req[i][1]]--;
            fun(req,i+1,temp,cnt);
        // }

        // return cnt;
    }
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int>temp(n,0);

        fun(req,0,temp,0);

        return ans;
        
    }
};