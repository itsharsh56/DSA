class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minir = 0, maxir = m - 1;
        int minic = 0, maxic = n - 1;
        int t = n* m;
        int count = 0;
        vector<int> res;
        while (minir <= maxir && minic <= maxic) {
            // right
            for (int j = minic; j <= maxic && count < t; j++) {
                res.push_back(matrix[minir][j]);
                count++;
            }
            minir++;

            // down
            for (int i = minir; i <= maxir && count < t; i++) {
                res.push_back(matrix[i][maxic]);
                count++;
            }
            maxic--;

            // left
            for (int j = maxic; j >= minic && count < t; j--) {
                res.push_back(matrix[maxir][j]);
                count++;
            }
            maxir--;

            // up
            for (int i = maxir; i >= minir && count < t; i--) {
                res.push_back(matrix[i][minic]);
                count++;
            }
            minic++;
        }
        return res;
    }
};