#include <iostream>
using namespace std;





int removeDuplicates(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int index = 1;
	int length = n;
	int dup_num = 0;
	while (index < length){
		if (A[index-1] == A[index])
		{
			/* code */
			if (dup_num == 0)
			{
				/* code */
				dup_num ++;
				index ++;
			}
			else if (dup_num == 1)
			{
				/* code */
				for (int j = index; j < n-1; ++j)
				{
					/* code */
					A[j] = A[j+1];
				}
				length --;
			}
		}
		else {
			dup_num = 0;
			index ++;
		}
	}
	return length;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[6] = {1, 1, 1, 2, 2, 3};
	int n = removeDuplicates(A, 6);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cout <<A[i] <<endl;
	}
	return 0;
}