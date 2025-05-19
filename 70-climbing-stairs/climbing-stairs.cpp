class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;
        vector<int> climb(n + 1);
        climb[0] = climb[1] = 1;
        for (int i = 2; i <= n; i++) 
        {
            climb[i] = climb[i - 1] + climb[i - 2];
        }
        return climb[n];
    }
};