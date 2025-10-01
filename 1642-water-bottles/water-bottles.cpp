class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while (numBottles >= numExchange) {
            int full_bottle = numBottles / numExchange;//new full bottles
            int r = numBottles % numExchange; // leftover empty bottles
            ans += full_bottle;
            numBottles = full_bottle + r; // update bottles
        }

        return ans;
    }
};