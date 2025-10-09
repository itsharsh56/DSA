class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> totalTime(n, 0);

        for (int j = 0; j < m; ++j) {
            long long current = 0;

            // Calculate cumulative time for current mana
            for (int i = 0; i < n; ++i) {
                current =
                    max(current, totalTime[i]) + (long long)skill[i] * mana[j];
            }

            totalTime[n - 1] = current;

            // Adjust times backward for next iteration
            for (int i = n - 2; i >= 0; --i) {
                totalTime[i] =
                    totalTime[i + 1] - (long long)skill[i + 1] * mana[j];
            }
        }

        return totalTime[n - 1];
    }
};
