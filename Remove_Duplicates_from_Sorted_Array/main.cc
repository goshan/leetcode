#include <iostream>
using namespace std;





int removeDuplicates(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int index = 1;
	int length = n;
	while (index < length){
		if (A[index-1] == A[index])
		{
			/* code */
			for (int j = index; j < n-1; ++j)
			{
				/* code */
				A[j] = A[j+1];
			}
			length --;
		}
		else {
			index ++;
		}
	}
	return length;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[3] = {1, 1, 2};
	int n = removeDuplicates(A, 3);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout <<A[i] <<endl;
	}
	return 0;
}