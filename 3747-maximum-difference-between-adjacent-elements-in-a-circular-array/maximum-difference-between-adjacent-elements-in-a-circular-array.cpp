class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int ans =0 ;
        int n = nums.size();
        for ( int i =1; i<n ;i++)
            {
                int x = abs(nums[i] - nums[i-1]);
                if ( ans < x)
                {
                    ans = x;
                }
            }
        if (abs(nums[0] - nums[n-1]) > ans)
        {
            ans = abs (nums[0] - nums[n-1]);
        }
        return ans;
    }
}; 