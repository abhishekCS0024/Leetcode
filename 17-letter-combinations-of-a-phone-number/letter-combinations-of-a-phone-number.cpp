class Solution {
public:

    void fun(int index,vector<string>&ans,string &prefix,vector<string>&mp,string &digits){
        if(digits.size()==prefix.size()){
            ans.push_back(prefix);
            return;
        }
        int digit=digits[index]-'0';
        if (digit < 2 || digit > 9) {
            fun(index+1,ans, prefix,mp, digits);
            return;
        }
        for(char ch:mp[digit]){
            prefix.push_back(ch);
            fun(index+1,ans,prefix,mp,digits);
            prefix.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>ans;
        string prefix="";
        vector<string>mp= {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        fun(0,ans,prefix,mp,digits);
        return ans;
    }
};