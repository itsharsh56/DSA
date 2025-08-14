class Solution {
public:
    string largestGoodInteger(string num) {
        string max_good = "";

        for (int i = 0; i + 2 < num.size(); i++) {
            string sub = num.substr(i, 3);
            if (sub[0] == sub[1] && sub[1] == sub[2]) { // All same digit
                if (max_good == "" || sub > max_good) {
                    max_good = sub;
                }
            }
        }
        return max_good;
    }
};