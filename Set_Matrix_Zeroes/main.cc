#include <iostream>
#include <vector>
using namespace std;





void setZeroes(vector<vector<int> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		bool set = false;
		for (int j=0; j<matrix[i].size(); j++){
			if (matrix[i][j] == 0)
			{
				/* code */
				set = true;
				for (int k=0; k<matrix.size(); k++){
					if (matrix[k][j] != 0)
					{
						/* code */
						matrix[k][j] = -1000000;
					}
				}
			}
		}
		if (set)
		{
			/* code */
			for (int j=0; j<matrix[i].size(); j++){
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		for (int j=0; j<matrix[i].size(); j++){
			if (matrix[i][j] == -1000000)
			{
				/* code */
				matrix[i][j] = 0;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);
	vector<int> b;
	b.push_back(0);
	b.push_back(3);
	b.push_back(4);
	vector<vector<int> > matrix;
	matrix.push_back(a);
	matrix.push_back(b);
	setZeroes(matrix);
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		for (int j=0; j<matrix[i].size(); j++){
			cout <<matrix[i][j] <<" ";
		}
		cout <<endl;
	}
	return 0;
}