class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                
                bool flag = true;
                for (int r = 0; r < m; r++) {
                    if (r != i && mat[r][j] == 1) {
                        flag = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; c++) {
                    if (c != j && mat[i][c] == 1) {
                        flag = false;
                        break;
                    }
                }
                
                if (flag) {
                    res++;
                }
            }
        }
        
        return res;
    }
};