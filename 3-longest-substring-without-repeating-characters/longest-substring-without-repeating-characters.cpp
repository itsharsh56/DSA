class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            if (freq.find(s[right]) != freq.end()) {
                left = max(left, freq[s[right]] + 1);
            }

            freq[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};