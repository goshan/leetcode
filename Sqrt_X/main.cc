#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;






int root_limit(int x){
	stringstream ss;
	ss <<x;
	string s = ss.str();
	int len = s.length()%2 == 0 ? s.length()/2 : s.length()/2+1;
	return pow(10, len);
}

int sqrt(int x) {
// Start typing your C/C++ solution below
// DO NOT write int main() function
	if (x == 0 || x == 1)
	{
		/* code */
		return x;
	}
	int s = 0;
	int e = root_limit(x);
	while (e-s != 1){
		int mid = (e-s)/2+s;
		int square = mid*mid;
		if (square == x)
		{
			/* code */
			return mid;
		}
		else if (square > 0 && square < x)
		{
			/* code */
			s = mid;
		}
		else {
			e = mid;
		}
	}
	return s;
}



int main(int argc, char const *argv[])
{
	/* code */
	cout <<INT_MAX <<endl;
	cout <<sqrt(2147395599) <<endl;
	return 0;
}