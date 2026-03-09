class Solution {
public:
    int n;
    vector<string>result;

    bool isvalid(string s){
        if(s[0]=='0') return false;
        int temp=stoi(s);

        return temp<=255;
    }

    void solve(string &s, int idx,int part, string curr){
        if(idx==n && part==4){
            result.push_back(curr.substr(0,curr.size()-1));
            return;
        }

        if(idx<n){
            solve(s,idx+1,part+1,curr+s.substr(idx,1)+".");
        }
        if(idx+1<n && isvalid(s.substr(idx,2))){
            solve(s, idx+2, part+1, curr + s.substr(idx, 2) + ".");
        }
        if(idx+2<n && isvalid(s.substr(idx,3))){
            solve(s, idx+3, part+1, curr + s.substr(idx, 3) + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n=s.size();

        if(n>12) return {};

        int part=0;

        string curr="";

        solve(s,0,part,curr);

        return result;
    }
};