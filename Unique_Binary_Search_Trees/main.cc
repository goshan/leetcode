#include <iostream>
#include <vector>
using namespace std;







int numTrees(int n) {
// Start typing your C/C++ solution below
// DO NOT write int main() function
	vector<int> num(n+1, 0);
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		/* code */
		for (int j=0; j<=i-1; j++){
			num[i] += num[j]*num[i-1-j];
		}
	}
	return num[n];
}

int main(int argc, char const *argv[])
{
	/* code */
	cout <<numTrees(3) <<endl;
	return 0;
}