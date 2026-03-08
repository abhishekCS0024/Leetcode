// class Solution {
// public:
//     bool isSorted(string s){
//         string temp=s;

//         sort(temp.begin(),temp.end());

//         return temp==s;
//     }
//     // oool -> oloo -> looo
//     int minOperations(string s) {
//         // -1 , 1 , 2 , 3
//         // abc  acb  cab ceba -> abbceaa -> 
//         int cnt=0;

//         if(isSorted(s)) return cnt;

//         if(s.size()==2) return -1;
//         string temp;
//         temp=s.substr(0,s.size()-1);
//         sort(temp.begin(),temp.end());
//         if(isSorted(temp+s[s.size()-1])) return 1;

//         temp=s.substr(1,s.size()-1);
//         sort(temp.begin(),temp.end());
//         if(isSorted(s[0]+temp)) return 1;

//         temp=s.substr(0,s.size()-1);
//         sort(temp.begin(),temp.end());
//         string temp1=temp+s[s.size()-1];
//         string temp2=temp1.substr(1,temp2.size()-1);
//         sort(temp2.begin(),temp2.end());

//         if(isSorted(temp[0]+temp2)) return 2;

//         return 3;

//     }
// };

class Solution {
public:
    int minOperations(string s) {
    if (is_sorted(begin(s), end(s)))
        return 0;
    if (s.size() == 2)
        return -1;
    auto [min_p, max_p] = minmax_element(next(begin(s)), prev(end(s)));
    if (s[0] <= s.back() && (*min_p >= s[0] || *max_p <= s.back()))
        return 1;
    return s.back() < *min_p && s[0] > *max_p ? 3 : 2;
}};
//     int minOperations(string s) {
//         string sorted = s;
//         sort(sorted.begin(), sorted.end());

//         int i = s.size() - 1;
//         int j = sorted.size() - 1;

//         int match = 0;

//         while(i >= 0 && j >= 0) {
//             if(s[i] == sorted[j]) {
//                 match++;
//                 j--;
//             }
//             i--;
//         }

//         return s.size() - match;
//     }
// };