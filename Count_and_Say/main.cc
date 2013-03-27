#include <iostream>
#include <string>
#include <sstream>
using namespace std;





string com_next(string s){
	stringstream ss;
	int count = 1;
	if (s.length() == 1)
	{
		/* code */
		ss <<1 <<s[0];
	}
	for (int i = 1; i < s.length(); ++i)
	{
		/* code */
		if (s[i] == s[i-1])
		{
			/* code */
			count ++;
		}
		else {
			ss <<count <<s[i-1];
			count = 1;
		}
		if (i == s.length()-1)
		{
			/* code */
			ss <<count <<s[i];
		}
	}
	return ss.str();
}

string countAndSay(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string res = "1";
    for (int i = 1; i < n; ++i)
	{
		/* code */
		res = com_next(res);
	}
    return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	while (1){
		int n = 0;
		cin >>n;
		cout <<countAndSay(n) <<endl;
	}
	return 0;
}