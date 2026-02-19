class Solution {
public:
    int countBinarySubstrings(const std::string& s) {
        int ans = 0, prev = 0, cur = 1;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i-1] != s[i]) {
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }
        return ans + min(prev, cur);
    }
};