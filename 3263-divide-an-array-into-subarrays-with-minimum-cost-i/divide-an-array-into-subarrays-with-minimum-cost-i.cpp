class Solution {
public:
    int minimumCost(vector<int>& A) {
    int n = A.size();
    int ans = INT_MAX;

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, A[0] + A[i] + A[j]);
        }
    }
    return ans;
    }
};