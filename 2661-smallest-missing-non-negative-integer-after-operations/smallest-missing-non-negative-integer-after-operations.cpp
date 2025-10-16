class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);

        for (int num : nums) {
            int val = ((num % value) + value) % value;
            count[val]++;
        }

        int mini = 0;
        while (count[mini % value] > 0) {
            count[mini % value]--;
            mini++;
        }

        return mini;
    }
};
