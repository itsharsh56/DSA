class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if (n <= 0) 
        {
            return false;
        }
        for (long long i = 1; i <= n; i = i * 4) 
        {
            if (i == n) 
            {
                return true;
            }
        }
        return false;
    }
};