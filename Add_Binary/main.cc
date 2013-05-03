#include <iostream>
#include <string>
using namespace std;





string addBinary(string a, string b) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	string res = a.length() < b.length() ? b : a;
	string temp = a.length() < b.length() ? a : b;
	int sub = res.length()-temp.length();
	bool seg = false;
	for (int i=res.length()-1; i>=0; i--){
		int j = i-sub;
		char add = '0';
		if (j >= 0)
		{
			/* code */
			add = temp[j];
		}
		if (res[i] == '0' && add == '0')
		{
			/* code */
			res[i] = seg+'0';
			seg = false;
		}
		else if (res[i] == '0' || add == '0')
		{
			/* code */
			if (seg)
			{
				/* code */
				res[i] = '0';
				seg = true;
			}
			else {
				res[i] = '1';
				seg = false;
			}
		}
		else if (res[i] == '1' && add == '1')
		{
			/* code */
			res[i] = seg+'0';
			seg = true;
		}
	}
	if (seg)
	{
		/* code */
		res = "1"+res;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	string a = "11";
	string b = "1";
	string res = addBinary(a, b);
	cout <<res <<endl;
	return 0;
}