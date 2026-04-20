class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int minir = 0, maxir = n - 1;
        int minic = 0, maxic = n - 1;
        int t = n* n;
        int count = 0;
        int a = 1;
        while (count < t) {
            // right
            for (int j = minic; j <= maxic && count < t; j++) {
                matrix[minir][j] = a++;
                count++;
            }
            minir++;

            // down
            for (int i = minir; i <= maxir && count < t; i++) {
                matrix[i][maxic] = a++;
                count++;
            }
            maxic--;

            // left
            for (int j = maxic; j >= minic && count < t; j--) {
                matrix[maxir][j] = a++;
                count++;
            }
            maxir--;

            // up
            for (int i = maxir; i >= minir && count < t; i--) {
                matrix[i][minic] = a++;
                count++;
            }
            minic++;
        }

        return matrix;
    }
};