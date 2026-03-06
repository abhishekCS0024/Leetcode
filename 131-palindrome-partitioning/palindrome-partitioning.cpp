class Solution {
public:
    vector<vector<string>>result;
    int n;

    bool ispalindrome(string &s){
        int i=0,j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }

        return true;
    }

    void fun(string s,vector<string>&curr_partision){

        if(s.size()==0){
            result.push_back(curr_partision);
            return;
        }
        for(int i=0;i<s.size();i++){
            string temp=s.substr(0,i+1);
            if(ispalindrome(temp)){
                curr_partision.push_back(temp);
                fun(s.substr(i+1),curr_partision);
                curr_partision.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<string>partision;
        fun(s,partision);

        return result;
    }
};