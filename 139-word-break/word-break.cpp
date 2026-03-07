class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};

// // Pure Recursion

// class Solution {
// public:
//     unordered_set<string>st;
//     int n;
//     bool fun(string s){
//         if(s.size()==0) return true;
//         if(st.count(s)) return true;

//         for(int i=0;i<s.size();i++){
//             string temp=s.substr(0,i+1);

//             if(st.count(temp) && fun(s.substr(i+1))){
//                 return true;
//             }
//         }

//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         n=s.size();
//         for(int i=0;i<wordDict.size();i++){
//             st.insert(wordDict[i]);
//         }

//         if(fun(s)) return true;

//         return false;
//     }
// };