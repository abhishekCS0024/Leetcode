class Solution {
public:
    string bit(int n){
        string ans="";

        while(n>0){
            if(n%2==0){
                ans+="0";
            }
            else{
                ans+="1";
            }
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string s=bit(n);

        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        int ans=0;
        int p=0;
        int i=s.size()-1;

        while(i>=0){
            if(s[i]=='0'){
                p++;                
            }
            else ans+=pow(2,p++);
            i--;
        }

        return ans;
    }
};