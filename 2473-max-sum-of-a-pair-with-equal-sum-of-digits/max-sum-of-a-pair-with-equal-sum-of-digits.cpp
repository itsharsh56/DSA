class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> digitSumMap;

        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            digitSumMap[digitSum].push_back(num);
        }

        int maxSumValue = -1;

        for (auto& entry : digitSumMap) {
            vector<int>& values = entry.second;

            sort(values.begin(), values.end(), greater<int>());

            if (values.size() > 1) {
                maxSumValue = max(maxSumValue, values[0] + values[1]);
            }
        }

        return maxSumValue;
    }
};