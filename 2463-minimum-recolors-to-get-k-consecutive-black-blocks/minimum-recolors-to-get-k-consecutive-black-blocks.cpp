class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, white = 0, color = INT_MAX;
        for (int r = 0; r < blocks.size(); r++) {
            if (blocks[r] == 'W') {
                white++;
            }

            if (r - l + 1 == k) {
                color = min(color, white);

                if (blocks[l] == 'W') white--;

                l++;
            }
        }
        return color;
    }
};