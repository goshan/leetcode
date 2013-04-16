#include <iostream>
using namespace std;




double pow(double x, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0)
	{
		/* code */
		return 1.0;
	}
	else if (n < 0.0)
	{
		/* code */
		n = 0-n;
		x = 1/x;
	}

	double temp = pow(x, n/2);
	if (n%2 == 0)
	{
		/* code */
		return temp*temp;
	}
	else {
		return temp*temp*x;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	double x = 1.2;
	int n = -3;
	cout <<pow(x, n) <<endl;
	return 0;
}