class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , curr = 0;;

        for(int x : nums)
        {
            if(x == 1)
            {
                curr++;
                count = max(count , curr);
            }
            else
            {
                curr = 0;
            }
        }
        return count;
    }
};