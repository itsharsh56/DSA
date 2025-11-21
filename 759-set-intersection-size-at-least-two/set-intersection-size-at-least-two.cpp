#include <vector>
#include <algorithm>

class Solution {
public:
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] != b[0]) ? (a[0] < b[0]) : (a[1] > b[1]);
        });
        std::vector<int> todo(intervals.size(), 2);
        int ans = 0;
        int t = intervals.size();
        while (--t >= 0) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];
            for (int p = s; p < s + m; ++p) {
                for (int i = 0; i <= t; ++i) {
                    if (todo[i] > 0 && p <= intervals[i][1]) {
                        todo[i]--;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};