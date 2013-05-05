#include <iostream>
using namespace std;





bool canJump(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i = 0;
	while (i < n){
		if (i == n-1)
		{
			/* code */
			return true;
		}
		else if (A[i] == 0)
		{
			/* code */
			return false;
		}
		i += A[i];
	}
	return true;
}


int main(int argc, char const *argv[])
{
	/* code */
	int A[5] = {2, 3, 1, 0, 4};
	cout <<canJump(A, 5) <<endl;
	return 0;
}