class Solution {
public:
  void moveZeroes(vector<int>& nums) {
      int n = nums.size();
      int j = -1;

      // count zeros
      for(int i = 0;i < n;i++)
      {
        if(nums[i] == 0)
        {
            j = i;
            break;
        }
      }

      // if no zeros found
      if(j == -1) return;

      // start i form j+1
      for(int i = j + 1; i < n;i++)
      {
        //if non-zero element found then swap 
        if(nums[i] != 0)
        {
            swap(nums[i],nums[j]);
            j++; // update j
        }
      }
  }
};