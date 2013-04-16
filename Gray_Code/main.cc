#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;






void gen_next(string &s, bool odd){
	if (odd)
	{
		/* code */
		s[s.length()-1] = '1'-s[s.length()-1]+'0';
	}
	else {
		for (int i = s.length()-1; i >= 0; --i)
		{
			/* code */
			if (s[i] == '1')
			{
				/* code */
				s[i-1] = '1'-s[i-1]+'0';
				break;
			}
		}
	}
}

int to_int(string s){
	int res = 0;
	for (int i = s.length()-1; i >= 0; --i)
	{
		/* code */
		res += (s[i]-'0')*pow(2, s.length()-i-1);
	}
	return res;
}

vector<int> grayCode(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	string code = "";
	for (int i = 0; i < n; ++i)
	{
		/* code */
		code += "0";
	}
	bool odd = true;
	vector<int> res;
	for (int i = 0; i < pow(2, n); ++i)
	{
		/* code */
		res.push_back(to_int(code));
		gen_next(code, odd);
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