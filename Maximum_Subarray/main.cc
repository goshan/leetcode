#include <iostream>
using namespace std;






int maxSubArray(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int max = A[0];
	int min = A[0] > 0 ? 0 : A[0];
	for (int i = 1; i < n; ++i)
	{
		/* code */
		A[i] += A[i-1];
		int sub = A[i]-min;
		if (sub > max)
		{
			/* code */
			max = sub;
		}
		if (A[i] < min)
		{
			/* code */
			min = A[i];
		}
	}
	return max;
}



int main(int argc, char const *argv[])
{
	/* code */
	int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout <<maxSubArray(A, 9) <<endl;
	return 0;
}