#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;






int gen_next(int s, bool odd){
	int bit = 0;
	if (odd)
	{
		/* code */
		bit = 1;
	}
	else {
		bit = (s & (-s)) << 1;
	}
	return s ^ bit;
}


vector<int> grayCode(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int code = 0;
	bool odd = true;
	vector<int> res;
	for (int i = 0; i < pow(2, n); ++i)
	{
		/* code */
		res.push_back(code);
		code = gen_next(code, odd);
		odd = !odd;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> res = grayCode(3);
	for (int i=0; i<res.size(); i++){
		cout <<res[i] <<endl;
	}
	return 0;
}