class Solution {
public:
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1, cur = a % mod;
        while (b) {
            if (b & 1)
                res = res * cur % mod;
            cur = cur * cur % mod;
            b >>= 1;
        }
        return res;
    }

    int magicalSum(int m, int k, vector<int>& arr) {
        int n = arr.size();
        const long long mod = 1e9 + 7;

        vector<long long> fact(m + 1, 1), inv(m + 1, 1);
        for (int i = 1; i <= m; i++)
            fact[i] = fact[i - 1] * i % mod;
        for (int i = 2; i <= m; i++)
            inv[i] = modPow(i, mod - 2, mod);
        for (int i = 2; i <= m; i++)
            inv[i] = inv[i - 1] * inv[i] % mod;

        vector pw(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                pw[i][j] = pw[i][j - 1] * arr[i] % mod;

        vector dp(
            n, vector(m + 1, vector(m * 2 + 1, vector<long long>(k + 1, 0))));
        for (int j = 0; j <= m; j++)
            dp[0][j][j][0] = pw[0][j] * inv[j] % mod;

        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = p % 2 + q;
                        if (q2 > k)
                            break;
                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            dp[i + 1][j + r][p2][q2] =
                                (dp[i + 1][j + r][p2][q2] +
                                 dp[i][j][p][q] * pw[i + 1][r] % mod * inv[r]) %
                                mod;
                        }
                    }
                }
            }
        }

        long long ans = 0;
        for (int p = 0; p <= m * 2; p++)
            for (int q = 0; q <= k; q++)
                if (__builtin_popcount(p) + q == k)
                    ans = (ans + dp[n - 1][m][p][q] * fact[m]) % mod;

        return ans;
    }
};
