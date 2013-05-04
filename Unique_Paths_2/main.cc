#include <iostream>
#include <vector>
using namespace std;







int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int> > num(m, vector<int> (n, 0));
	num[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
	for (int i = 1; i < m; ++i)
	{
		/* code */
		num[i][0] = obstacleGrid[i][0] == 1 ? 0 : num[i-1][0];
	}
	for (int i = 1; i < n; ++i)
	{
		/* code */
		num[0][i] = obstacleGrid[0][i] == 1 ? 0 : num[0][i-1];
	}
	for (int i = 1; i < m; ++i)
	{
		/* code */
		for (int j=1; j<n; j++){
			num[i][j] = obstacleGrid[i][j] == 1 ? 0 : num[i-1][j]+num[i][j-1];
		}
	}
	return num.back().back();
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(0);
	vector<int> b;
	b.push_back(0);
	b.push_back(1);
	b.push_back(0);
	vector<int> c;
	c.push_back(0);
	c.push_back(0);
	c.push_back(0);
	vector<vector<int> > obstacleGrid;
	obstacleGrid.push_back(a);
	obstacleGrid.push_back(b);
	obstacleGrid.push_back(c);
	cout <<uniquePathsWithObstacles(obstacleGrid) <<endl;
	return 0;
}