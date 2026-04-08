class Solution {
public:
    bool hasMatch(string s, string p) {

        int x=p.find('*'); // returns the index of that character

        string s1=p.substr(0,x);
        string s2=p.substr(x+1);

        int i=s.find(s1);
        int j=s.rfind(s2);

        return i!=-1 && j!=-1 && i+s1.size()<=j;
    }
};