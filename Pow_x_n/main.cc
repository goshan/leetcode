#include <iostream>
#include <math.h>
using namespace std;




double power(double x, int n){
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

	if (n%2 == 0)
	{
		/* code */
		return pow(power(x, n/2), 2);
	}
	else {
		return pow(power(x, n/2), 2)*x;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	double x = 1.2;
	int n = -3;
	cout <<power(x, n) <<endl;
	return 0;
}