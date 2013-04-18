#include <iostream>
#include <string>
#include <vector>
using namespace std;






int numDecodings(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (s.empty())
	{
		/* code */
		return 0;
	}
	vector<int> num(s.length(), 0);
	num[0] = s[0] == '0' ? 0 : 1;
	num[1] = s[1] != '0' ? num[0] : 0;
	num[1] += s[0] != '0' && atoi(s.substr(0, 2).c_str()) <= 26 ? 1 : 0;
	for (int i = 2; i < num.size(); ++i)
	{
		/* code */
		if (s[i] != '0')
		{
			/* code */
			num[i] = num[i-1];
		}
		if (s[i-1] != '0' && atoi(s.substr(i-1, 2).c_str()) <= 26)
		{
			/* code */
			num[i] += num[i-2];
		}
	}
	return num.back();
}

int main(int argc, char const *argv[])
{
	/* code */
	string s = "27";
	cout <<numDecodings(s) <<endl;
	return 0;
}