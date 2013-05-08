#include <iostream>
#include <vector>
using namespace std;






int jump(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int longest = 0;
	int last_long = 0;
	int step = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (i > last_long)
		{
			/* code */
			last_long = longest;
			step ++;
		}
		longest = max(longest, i+A[i]);
	}
	return step;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[3] = {1, 2, 3};
	cout <<jump(A, 3) <<endl;
	return 0;
}