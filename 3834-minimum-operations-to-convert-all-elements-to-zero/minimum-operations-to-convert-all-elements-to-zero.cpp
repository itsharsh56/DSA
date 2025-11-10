class bit {
public:
    vector<int> b;
    int n;

    bit(int size) {
        n = size + 2;
        b.assign(n, 0);
    }

    void up(int i, int val) {
        i++; 
        while (i < n) {
            b[i] += val;
            i += i & -i;
        }
    }

    int q(int i) {
        i++; 
        int res = 0;
        while (i > 0) {
            res += b[i];
            i -= i & -i;
        }
        return res;
    }

    int sum(int l, int r) {
        return q(r) - q(l - 1);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int max_v = *max_element(nums.begin(), nums.end());

        bit b(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                b.up(i, 1);
            }
        }

        vector<vector<int>> p(max_v + 1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                p[nums[i]].push_back(i);
            }
        }

        int ops = 0;

        for (int v = 1; v <= max_v; ++v) {
            if (p[v].empty()) continue;

            int s = 0;
            int l = -1;

            for (int pos : p[v]) {
                if (l == -1 || b.sum(l + 1, pos - 1) > 0) {
                    s++;
                    l = pos;
                }
            }

            for (int pos : p[v]) {
                b.up(pos, 1);
            }

            ops += s;
        }

        return ops;
    }
};

