#include <iostream>
using namespace std;








bool search(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int l = 0;
	int r = n-1;
	while (l <= r){
		int m = (r-l)/2+l;
		if (A[m] == target)
		{
			/* code */
			return true;
		}
		bool asc = true;
		for (int i = l; i < m ; ++i)
		{
			/* code */
			if (A[i] > A[i+1])
			{
				/* code */
				asc = false;
				break;
			}
		}
		if (asc)
		{
			/* code */
			if (A[l] <= target && target < A[m])
			{
				/* code */
				r = m-1;
			}
			else {
				l = m+1;
			}
		}
		else {
			if (A[m] < target && target <= A[r])
			{
				/* code */
				l = m+1;
			}
			else {
				r = m-1;
			}
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[5] = {1, 3, 1, 1, 1};
	cout <<search(A, 5, 3) <<endl;
	return 0;
}