#include <iostream>
using namespace std;





int climbStairs(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int pp = 1;
	int p = 2;
	if (n == 0)
	{
		/* code */
		return 0;
	}
	else if (n == 1)
	{
		/* code */
		return pp;
	}
	else if (n == 2)
	{
		/* code */
		return p;
	}
	for (int i = 3; i <= n; ++i)
	{
		/* code */
		int current = pp+p;
		pp = p;
		p = current;
	}
	return p;
}


int main(int argc, char const *argv[])
{
	/* code */
	cout <<climbStairs(4) <<endl;
	return 0;
}