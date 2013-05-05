#include <iostream>
#include <vector>
using namespace std;




bool canMove(vector<vector<int> > &matrix, int i, int j, int dir){
	if (dir == 0)
	{
		/* code */
		if (j != matrix[i].size()-1 && matrix[i][j+1] == -100000)
		{
			/* code */
			return true;
		}
		else {
			return false;
		}
	}
	else if (dir == 1)
	{
		/* code */
		if (i != matrix.size()-1 && matrix[i+1][j] == -100000)
		{
			/* code */
			return true;
		}
		else {
			return false;
		}
	}
	else if (dir == 2)
	{
		/* code */
		if (j != 0 && matrix[i][j-1] == -100000)
		{
			/* code */
			return true;
		}
		else {
			return false;
		}
	}
	else if (dir == 3)
	{
		/* code */
		if (i != 0 && matrix[i-1][j] == -100000)
		{
			/* code */
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

vector<vector<int> > generateMatrix(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0)
	{
		/* code */
		return vector<vector<int> >(0);
	}
	vector<vector<int> > res (n, vector<int> (n, -100000));
	int dir = 0;     //0--right, 1--down, 2--left, 3--up
	int row = 0;
	int col = 0;
	for (int i = 1; i <= n*n; ++i)
	{
		/* code */
		res[row][col] = i;
		if (!canMove(res, row, col, dir))
		{
			/* code */
			dir ++;
			dir %= 4;
		}
		if (dir == 0) col++;
		else if (dir == 1) row++;
		else if (dir == 2) col--;
		else if (dir == 3) row--;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int> > res = generateMatrix(3);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		for (int j=0; j<res[i].size(); j++){
			cout <<res[i][j] <<" ";
		}
		cout <<endl;
	}
	return 0;
}