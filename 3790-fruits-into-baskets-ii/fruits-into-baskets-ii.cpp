class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = baskets.size();
        for (auto fruit : fruits) {
            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    flag = 0;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};