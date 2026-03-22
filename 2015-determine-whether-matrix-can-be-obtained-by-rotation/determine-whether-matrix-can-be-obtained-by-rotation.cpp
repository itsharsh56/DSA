class Solution
{
public:
bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
	{
		for (int i = 0; i < 4; i++)
		{
			if (mat == target)
				return true;
			rotate(mat);
		}

		return false;
	}
private:
	void rotate(vector<vector<int>> &matrix)
	{
		int n = matrix.size();

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0, k = n - 1; j < k; j++, k--)
			{
				swap(matrix[i][j], matrix[i][k]);
			}
		}
	}
};