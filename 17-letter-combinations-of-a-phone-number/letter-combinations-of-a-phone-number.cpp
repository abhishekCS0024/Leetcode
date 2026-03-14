class Solution {
public:
    vector<string>result;
    void fun(string digits, int i,string &curr,vector<string>&temp){
        if(curr.size()==digits.size()){
            result.push_back(curr);
            return;
        }

        int digit=digits[i]-'0';
        if(digit==0|| digit==1){
            fun(digits,i+1,curr,temp);
            return;
        }

        for(int j=0;j<temp[digit].size();j++){
            curr.push_back(temp[digit][j]);
            fun(digits,i+1,curr,temp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>temp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string curr="";
        fun(digits,0,curr,temp);
        return result;
    }
};