#include <iostream>
#include <vector>
using namespace std;






bool searchMatrix(vector<vector<int> > &matrix, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		if (target < matrix[i][0])
		{
			/* code */
			return false;
		}
		else if (matrix[i][0] <= target && target <= matrix[i].back())
		{
			/* code */
			for (int j=0; j<matrix[i].size(); j++){
				if (target == matrix[i][j])
				{
					/* code */
					return true;
				}
			}
			return false;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int> > matrix(3, vector<int> (4));
	matrix[0][0] = 1;
	matrix[0][1] = 3;
	matrix[0][2] = 5;
	matrix[0][3] = 7;
	matrix[1][0] = 10;
	matrix[1][1] = 11;
	matrix[1][2] = 16;
	matrix[1][3] = 20;
	matrix[2][0] = 23;
	matrix[2][1] = 30;
	matrix[2][2] = 34;
	matrix[2][3] = 50;
	cout <<searchMatrix(matrix, 3) <<endl;
	return 0;
}