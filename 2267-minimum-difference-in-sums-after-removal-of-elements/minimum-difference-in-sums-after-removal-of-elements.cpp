class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;

    // left_sums[i] = minimum sum of n elements in nums[0..i]
    priority_queue<int> maxHeap; // max-heap for left
    long long leftSum = 0;
    vector<long long> leftSums(nums.size(), 0);

    for (int i = 0; i < nums.size(); ++i) {
        maxHeap.push(nums[i]);
        leftSum += nums[i];
        if (maxHeap.size() > n) {
            leftSum -= maxHeap.top();
            maxHeap.pop();
        }
        if (i >= n - 1) {
            leftSums[i] = leftSum;
        }
    }

    // right_sums[i] = maximum sum of n elements in nums[i..end]
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for right
    long long rightSum = 0;
    vector<long long> rightSums(nums.size(), 0);

    for (int i = nums.size() - 1; i >= 0; --i) {
        minHeap.push(nums[i]);
        rightSum += nums[i];
        if (minHeap.size() > n) {
            rightSum -= minHeap.top();
            minHeap.pop();
        }
        if (i <= 2 * n) {
            rightSums[i] = rightSum;
        }
    }

    long long result = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; ++i) {
        result = min(result, leftSums[i] - rightSums[i + 1]);
    }

    return result;
}
};