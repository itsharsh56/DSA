class Solution {
public:
    int divide(int dividend, int divisor) {

        // M-1 brute force but it will give TLE

        // long long sum = 0, count = 0;
        // while (sum + divisor <= dividend) {
        //     count++;
        //     sum += divisor;
        // }
        // return count;

        // M-2

        if (dividend == divisor)
            return 1;

        bool sign = true; // number is +ve

        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend <= 0 && divisor > 0)
            sign = false;

        long long n = abs((long long)dividend), d = abs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            long long count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1LL << count;
            n = n - (d * (1LL << count));
        }

        if (ans >= (1LL << 31) && sign == true)
            return INT_MAX;
        if (ans >= (1LL << 31) && sign == false)
            return INT_MIN;

        return sign ? ans : (-1 * ans);
    }
};