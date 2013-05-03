#include <iostream>
#include <vector>
using namespace std;







int minPathSum(vector<vector<int> > &grid) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > sum(m, vector<int> (n, 0));
	sum[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i)
	{
		/* code */
		sum[i][0] = sum[i-1][0]+grid[i][0];
	}
	for (int i = 1; i < n; ++i)
	{
		/* code */
		sum[0][i] = sum[0][i-1]+grid[0][i];
	}
	for (int i = 1; i < m; ++i)
	{
		/* code */
		for (int j=1; j<n; j++){
			sum[i][j] = sum[i-1][j] < sum[i][j-1] ? sum[i-1][j] : sum[i][j-1];
			sum[i][j] += grid[i][j];
		}
	}

	return sum.back().back();
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector<int> b;
	b.push_back(3);
	b.push_back(1);
	b.push_back(4);
	vector<int> c;
	c.push_back(4);
	c.push_back(3);
	c.push_back(2);
	vector<vector<int> > grid;
	grid.push_back(a);
	grid.push_back(b);
	grid.push_back(c);
	cout <<minPathSum(grid) <<endl;
	return 0;
}