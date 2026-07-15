class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {   
        //M-1 -> using XOR
        int n=0;
        for (int i =0;i<nums.size();i++)
        {
            n^=nums[i];   
        }
        return n;

//M-2 -> using map
        // unordered_map<int,int>freq;
        // for(int i: nums)
        // {
        //     freq[i]++;
        // }

        // for(auto i: freq)
        // {
        //     if(i.second == 1)
        //     return i.first;
        // }
        // return -1;
    }
};