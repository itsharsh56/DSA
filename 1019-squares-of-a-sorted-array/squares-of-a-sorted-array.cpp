class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>arr;
        long long square;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            square = nums[i] * nums[i];
            arr.push_back(square);
        }
        sort(arr.begin(),arr.end());
        return arr;
    }
};