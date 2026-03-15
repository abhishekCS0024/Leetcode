class Solution {
public:
    int countCommas(int n) {
        // 1 to 100,000

        if(n<=999) return 0;

        return n-999;
    }
};