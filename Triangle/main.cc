#include <iostream>
#include <vector>
using namespace std;




int min (const int &a, const int &b){
	return a < b ? a : b;
}

int minimumTotal(vector<vector<int> > &triangle) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	for (int i = triangle.size()-2; i >= 0; --i)
	{
		/* code */
		for (int j=0; j<triangle[i].size(); j++){
			triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
		}
	}
	return triangle[0][0];
}

int main(int argc, char const *argv[])
{
	/* code */
	int row;
	cin >>row;
	vector<vector<int> > triangle;
	for (int i = 0; i < row; ++i)
	{
		/* code */
		vector<int> elem;
		for (int j=0; j<i+1; j++){
			int n;
			cin >>n;
			elem.push_back(n);
		}
		triangle.push_back(elem);
	}

	cout <<minimumTotal(triangle) <<endl;
	return 0;
}