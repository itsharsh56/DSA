class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        if (s == goal) {
            unordered_map<char, int> count;
            for (char c : s) {
                count[c]++;
                if (count[c] > 1)
                    return true;
            }
            return false;
        }

        vector<int> index;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                index.push_back(i);
            }
        }

        if (index.size() != 2)
            return false;

        int i = index[0], j = index[1];
        return s[i] == goal[j] && s[j] == goal[i];
    }
};