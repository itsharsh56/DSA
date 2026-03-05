class Solution {
public:
    int minOperations(string s) {
        int zeros = 0;
        int ones = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    ones++;
                } else {
                    zeros++;
                }
            } else {
                if (s[i] == '1') {
                    ones++;
                } else {
                    zeros++;
                }
            }
        }
        
        return min(zeros, ones);
    }
};