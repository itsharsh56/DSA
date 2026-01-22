class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;

        while (nums.size() > 1) {
            bool flag = true;
            int minSum = numeric_limits<int>::max();
            int targetIndex = -1;

            for (size_t i = 0; i < nums.size() - 1; ++i) {
                int sum = nums[i] + nums[i + 1];

                if (nums[i] > nums[i + 1]) {
                    flag = false;
                }

                if (sum < minSum) {
                    minSum = sum;
                    targetIndex = static_cast<int>(i);
                }
            }

            if (flag) {
                break;
            }

            count++;
            nums[targetIndex] = minSum;
            nums.erase(nums.begin() + targetIndex + 1);
        }

        return count;
    }
};