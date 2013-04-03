#include <iostream>
#include <vector>
using namespace std;




vector<int> getRow(int rowIndex) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> res;
	res.push_back(1);
	if (rowIndex == 0)
	{
		/* code */
		return res;
	}
	for (int i = 0; i < rowIndex; ++i)
	{
		/* code */
		vector<int> temp = res;
		for (int j=1; j<res.size(); j++){
			res[j] = temp[j-1]+temp[j];
		}
		res.push_back(1);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	int rowIndex = 3;
	vector<int> res = getRow(rowIndex);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<" ";
	}
	cout <<endl;
	return 0;
}