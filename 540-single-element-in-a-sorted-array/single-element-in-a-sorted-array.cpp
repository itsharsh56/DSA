class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // M-1 XOR
        //  int ans = 0;
        //  //slower as it uses O(n) time complexity
        //  for (int x : nums) {
        //      ans ^= x;
        //  }
        //  return ans;

        // M-2 using map to count the freq.

        // M-3 using Binary Search

        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];

            // left side
            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                {
                    low = mid + 1; // eliminates left half
                }
            // right side 
            else
            {
                high = mid - 1; // eliminates right half
            }
        }
        return -1;
    }
};