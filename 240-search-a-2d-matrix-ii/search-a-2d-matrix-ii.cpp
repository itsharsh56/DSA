class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = 0;
        int cols = matrix[0].size() - 1;

        while(rows < matrix.size() && cols >= 0)
        {
            if(matrix[rows][cols] == target) return true;
            else if (matrix[rows][cols] > target) cols--;
            else rows++;
        }
        return false;
    }
};