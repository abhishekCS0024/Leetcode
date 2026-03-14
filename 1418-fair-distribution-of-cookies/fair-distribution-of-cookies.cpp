class Solution {
public:
    int mini=INT_MAX;
    void fun(vector<int>& cookies, int k,int idx,vector<int>&k_child){
        if(idx==cookies.size()){
            int maxi=INT_MIN;

            for(int i=0;i<k;i++){
                maxi=max(maxi,k_child[i]);
            }

            mini=min(mini,maxi);

            return;
        }

        for(int i=0;i<k;i++){
            k_child[i]+=cookies[idx];
            fun(cookies,k,idx+1,k_child);
            k_child[i]-=cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>k_child(k,0);
        fun(cookies,k,0,k_child);
        return mini;
    }
};