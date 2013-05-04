#include <iostream>
#include <vector>
using namespace std;








int uniquePaths(int m, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > num(m, vector<int> (n, 0));
	num[0][0] = 1;
	for (int i = 1; i < m; ++i)
	{
		/* code */
		num[i][0] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		/* code */
		num[0][i] = 1;
	}
	for (int i = 1; i < m; ++i)
	{
		/* code */
		for (int j=1; j<n; j++){
			num[i][j] = num[i][j-1]+num[i-1][j];
		}
	}
	return num.back().back();
}


int main(int argc, char const *argv[])
{
	/* code */
	cout <<uniquePaths(3, 7) <<endl;
	return 0;
}