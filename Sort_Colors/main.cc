#include <iostream>
using namespace std;






bool swap(int a[], int &tail, int current){
	/* code */
	int temp = a[tail];
	a[tail] = a[current];
	a[current] = temp;
}

void sortColors(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int red_tail = 0;
	int white_tail = 0;
	int last_num = -1;
	int i=0;
	for (int i=0; i<n; i++){
		if (A[i] == 0)
		{
			/* code */
			swap(A, red_tail, i);
			red_tail ++;
			white_tail = white_tail < red_tail ? red_tail : white_tail;
			if (A[i] == 1)
			{
				/* code */
				swap(A, white_tail, i);
				white_tail ++;
			}
		}
		else if (A[i] == 1)
		{
			/* code */
			swap(A, white_tail, i);
			white_tail ++;
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[8] = {1, 1, 2, 0, 1, 1, 1, 2};
	sortColors(A, 8);
	for (int i = 0; i < 8; ++i)
	{
		/* code */
		cout <<A[i] <<endl;
	}
	return 0;
}