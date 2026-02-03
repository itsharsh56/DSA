class Solution {
public:
    bool isInc(vector<int>& a, int l, int r) {
        for (int i = l; i < r; i++)
            if (a[i] >= a[i + 1]) return false;
        return true;
    }

    bool isDec(vector<int>& a, int l, int r) {
        for (int i = l; i < r; i++)
            if (a[i] <= a[i + 1]) return false;
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for (int p = 1; p <= n - 3; p++) {
            for (int q = p + 1; q <= n - 2; q++) {
                if (isInc(nums, 0, p) &&
                    isDec(nums, p, q) &&
                    isInc(nums, q, n - 1))
                    return true;
            }
        }
        return false;
    }
};
