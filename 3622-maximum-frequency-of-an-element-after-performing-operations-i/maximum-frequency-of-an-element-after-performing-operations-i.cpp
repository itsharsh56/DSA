class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        int bestFreq = 0;
        unordered_map<int, int> freqMap;

        int start = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[start]) {
                freqMap[nums[start]] = i - start;
                bestFreq = max(bestFreq, i - start);
                start = i;
            }
        }

        freqMap[nums[start]] = nums.size() - start;
        bestFreq = max(bestFreq, (int)nums.size() - start);

        auto lowerLimit = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value)
                    left = mid + 1;
                else
                    right = mid;
            }
            return left;
        };

        auto upperLimit = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value)
                    right = mid - 1;
                else
                    left = mid;
            }
            return left;
        };

        for (int val = nums.front(); val <= nums.back(); ++val) {
            int leftIndex = lowerLimit(val - k);
            int rightIndex = upperLimit(val + k);

            int possibleFreq;
            if (freqMap.count(val))
                possibleFreq =
                    min(rightIndex - leftIndex + 1, freqMap[val] + numOperations);
            else
                possibleFreq = min(rightIndex - leftIndex + 1, numOperations);

            bestFreq = max(bestFreq, possibleFreq);
        }

        return bestFreq;
    }
};