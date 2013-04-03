#include <iostream>
#include <vector>
using namespace std;






vector<vector<int> > generate(int numRows) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > res;
	if (numRows == 0)
	{
		/* code */
		return res;
	}
	vector<int> elem;
	elem.push_back(1);
	res.push_back(elem);
	if (numRows == 1)
	{
		/* code */
		return res;
	}
	for (int i = 1; i < numRows; ++i)
	{
		/* code */
		vector<int> elem;
		elem.push_back(1);
		for (int j=1; j<i; j++){
			elem.push_back(res[i-1][j-1]+res[i-1][j]);
		}
		elem.push_back(1);
		res.push_back(elem);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	int numRows = 5;
	vector<vector<int> > res = generate(numRows);
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