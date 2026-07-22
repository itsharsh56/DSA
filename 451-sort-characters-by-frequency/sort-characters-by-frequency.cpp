class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (auto i : mp) {
            maxHeap.push({i.second, i.first});
        }

        string ans;

        while (maxHeap.size() > 0) {
            int count = maxHeap.top().first;
            int num = maxHeap.top().second;

            while (count--) {
                ans.push_back(num);
            }
            maxHeap.pop();
        }
        return ans;
    }
};