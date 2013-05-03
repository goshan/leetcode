#include <iostream>
#include <vector>
using namespace std;






vector<int> minimumPathSum(vector<vector<int> > &grid, int m, int n){
	vector<vector<int> > sum(m, vector<int> (n, 0));
	vector<vector<int> > direction(m, vector<int> (n, 0)); //0--unknow, 1--from left, 2--from up
	sum[0][0] = grid[0][0];
	direction[0][0] = 0;
	for (int i = 1; i < m; ++i)
	{
		/* code */
		sum[i][0] = sum[i-1][0]+grid[i][0];
		direction[i][0] = 2;
	}
	for (int i = 1; i < n; ++i)
	{
		/* code */
		sum[0][i] = sum[0][i-1]+grid[0][i];
		direction[0][i] = 1;
	}
	for (int i = 1; i < m; ++i)
	{
		/* code */
		for (int j=1; j<n; j++){
			sum[i][j] = sum[i-1][j] < sum[i][j-1] ? sum[i-1][j] : sum[i][j-1];
			sum[i][j] += grid[i][j];
			direction[i][j] = sum[i-1][j] < sum[i][j-1] ? 2 : 1;
		}
	}

	vector<int> temp_res;
	int row = m-1;
	int col = n-1;
	while (row != 0 || col != 0){
		temp_res.push_back(grid[row][col]);
		if (direction[row][col] == 1)
		{
			/* code */
			col --;
		}
		else {
			row --;
		}
	}
	temp_res.push_back(grid[0][0]);
	vector<int> res;
	for (int i=temp_res.size()-1; i>=0; i--){
		res.push_back(temp_res[i]);
	}
	return res;
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
	vector<int> res = minimumPathSum(grid, 3, 3);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}