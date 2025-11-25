class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int check = 0;
        for ( int i = 1; i <= k; i++)
        {
            check = (check * 10 + 1) % k;
            if(check == 0)
            {
                return i;
            }
        }
        return -1;
    }
};