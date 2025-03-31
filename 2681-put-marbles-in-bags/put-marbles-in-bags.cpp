class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> weight(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            weight[i] += weights[i] + weights[i + 1];
        }

        sort(weight.begin(), weight.end());

        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += weight[n - 2 - i] - weight[i];
        }

        return answer;
    }
};