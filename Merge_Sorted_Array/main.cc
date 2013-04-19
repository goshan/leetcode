#include <iostream>
using namespace std;






void merge(int A[], int m, int B[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int a_pointer = m-1;
	int b_pointer = n-1;
	int all_pointer = m+n-1;
	while (a_pointer != -1 && b_pointer != -1){
		if (A[a_pointer] > B[b_pointer])
		{
			/* code */
			A[all_pointer] = A[a_pointer];
			all_pointer --;
			a_pointer --;
		}
		else {
			A[all_pointer] = B[b_pointer];
			all_pointer --;
			b_pointer --;	
		}
	}
	if (a_pointer == -1 && b_pointer != -1)
	{
		/* code */
		for (int i = 0; i <= b_pointer; ++i)
		{
			/* code */
			A[i] = B[i];
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int A[1] = {0};
	int B[1] = {1};
	merge(A, 0, B, 1);
	for (int i = 0; i < 1; ++i)
	{
		/* code */
		cout <<A[i] <<endl;
	}
	return 0;
}