#include <iostream>
#include <string>
#include <sstream>
using namespace std;



bool isPalindrome(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	stringstream ss;
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		if (s[i] <= 'Z' && s[i] >= 'A')
		{
			/* code */
			ss <<(char)(s[i]-'A'+'a');
		}
		else if ((s[i] <= 'z' && s[i] >= 'a') || s[i] <= '9' && s[i] >= '0') 
		{
			/* code */
			ss <<s[i];
		}
	}
	string temp = ss.str();
	if (temp.length() == 0)
	{
		/* code */
		return true;
	}
	for (int i = 0; i < temp.length()/2; ++i)
	{
		/* code */
		if (temp[i] != temp[temp.length()-1-i])
		{
			/* code */
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	/* code */
	string s;
	getline(cin, s);
	cout <<isPalindrome(s) <<endl;
	return 0;
}