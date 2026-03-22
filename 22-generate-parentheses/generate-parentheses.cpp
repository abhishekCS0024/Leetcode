class Solution {
public:
    void par(string s,int l,int r,int n,vector<string>&ans){
        if(l+r==2*n){
            ans.push_back(s);
            return;
        }
        if(l<n){
            s.push_back('(');
            par(s,l+1,r,n,ans);
            s.pop_back();
        }
        if(r<l){
            s.push_back(')');
            par(s,l,r+1,n,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        par(s,0,0,n,ans);
        return ans;
    }
};