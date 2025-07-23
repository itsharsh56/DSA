class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> tCount;
        for (char c : t) {
            tCount[c]++;
        }

        int required = tCount.size();
        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int startIdx = 0;
        unordered_map<char, int> windowCount;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            windowCount[c]++;

            if (tCount.find(c) != tCount.end() && windowCount[c] == tCount[c]) {
                formed++;
            }

            while (formed == required && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                if (tCount.find(leftChar) != tCount.end() &&
                    windowCount[leftChar] < tCount[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};