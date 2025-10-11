class Solution {
public:
    long long maximumTotalDamage(vector<int>& pwr) {
        map<int, int> freq;
        for (int x : pwr) freq[x]++;

        vector<pair<int, int>> v = {{-1e9, 0}};
        for (auto& it : freq) v.push_back(it);

        int n = v.size();
        vector<long long> dp(n);
        long long best = 0, res = 0;

        for (int i = 1, j = 1; i < n; i++) {
            while (j < i && v[j].first < v[i].first - 2)
                best = max(best, dp[j++]);
            dp[i] = best + 1LL * v[i].first * v[i].second;
            res = max(res, dp[i]);
        }
        return res;
    }
};
