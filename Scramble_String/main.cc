#include <iostream>
#include <vector>
#include <string>
using namespace std;







bool same_letters(string s1, string s2){
	vector<vector<int> > flag(2, vector<int> (26, 0));
	for (int i = 0; i < s1.length(); ++i)
	{
		/* code */
		flag[0][s1[i]-'a'] = 1;
		flag[1][s2[i]-'a'] = 1;
	}
	for (int i = 0; i < 26; ++i)
	{
		/* code */
		if (flag[0][i] != flag[1][i])
		{
			/* code */
			return false;
		}
	}
	return true;
}

bool isScramble(string s1, string s2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (s1.length() != s2.length())
	{
		/* code */
		return false;
	}
	if (s1.length() == 0)
	{
		/* code */
		return true;
	}
	else if (s1.length() == 1)
	{
		/* code */
		return s1 == s2;
	}
	for (int i = 1; i < s1.length(); ++i)
	{
		/* code */
		string s11 = s1.substr(0, i);
		string s12 = s1.substr(i, s1.length()-i);
		string s21 = s2.substr(0, i);
		string s22 = s2.substr(i, s2.length()-i);
		if (same_letters(s11, s21) && same_letters(s12, s22))
		{
			/* code */
			if (isScramble(s11, s21) && isScramble(s12, s22))
			{
				/* code */
				return true;
			}
			else {
				continue;
			}
		}
		s11 = s1.substr(0, i);
		s12 = s1.substr(i, s1.length()-i);
		s21 = s2.substr(0, s1.length()-i);
		s22 = s2.substr(s2.length()-i, i);
		if (same_letters(s11, s22) && same_letters(s12, s21))
		{
			/* code */
			if (isScramble(s11, s22) && isScramble(s12, s21))
			{
				/* code */
				return true;
			}
			else {
				continue;
			}
		}

	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	string s1 = "great";
	string s2 = "rgtae";
	cout <<isScramble(s1, s2) <<endl;
	return 0;
}