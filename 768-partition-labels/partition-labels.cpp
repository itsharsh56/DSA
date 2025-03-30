class Solution {
public:
    vector<int> partitionLabels(string s) {

        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }

        int end = 0, start = 0;
        vector<int> size;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                size.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return size;
    }
};