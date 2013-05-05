#include <iostream>
#include <vector>
using namespace std;




bool canMove(vector<vector<int> > &matrix, int i, int j, int dir){
	if (dir == 0)
	{
		/* code */
		if (j != matrix[i].size()-1 && matrix[i][j+1] != -100000)
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
		if (i != matrix.size()-1 && matrix[i+1][j] != -100000)
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
		if (j != 0 && matrix[i][j-1] != -100000)
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
		if (i != 0 && matrix[i-1][j] != -100000)
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

vector<int> spiralOrder(vector<vector<int> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> res;
	if (matrix.size() == 0)
	{
		/* code */
		return res;
	}
	int dir = 0;     //0--right, 1--down, 2--left, 3--up
	int i = 0;
	int j = 0;
	int m = matrix.size();
	int n = matrix[0].size();
	while (1){
		res.push_back(matrix[i][j]);
		matrix[i][j] = -100000;
		if (res.size() == m*n)
		{
			/* code */
			return res;
		}
		if (!canMove(matrix, i, j, dir))
		{
			/* code */
			dir ++;
			dir %= 4;
		}
		if (dir == 0) j++;
		else if (dir == 1) i++;
		else if (dir == 2) j--;
		else if (dir == 3) i--;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector<int> b;
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	vector<int> c;
	c.push_back(7);
	c.push_back(8);
	c.push_back(9);
	vector<vector<int> > matrix;
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	vector<int> res = spiralOrder(matrix);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}