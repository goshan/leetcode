#include <iostream>
#include <string>
#include <vector>
using namespace std;






vector<string> restoreIpAddresses(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<string> res;
	if (s.length() < 4 || s.length() > 12)
	{
		/* code */
		return res;
	}
	for (int i = 0; i < 3; ++i)
	{
		/* code */
		if ((s[0] == '0' && i > 0) || atoi(s.substr(0, i+1).c_str()) > 255)
		{
			/* code */
			continue;
		}
		for (int j=i+1; j<i+4; j++){
			if (j >= s.length()-1 || (s[i+1] == '0' && j-i > 1) || atoi(s.substr(i+1, j-i).c_str()) > 255)
			{
				/* code */
				continue;
			}
			for (int k=j+1; k<j+4; k++){
				if (k >= s.length()-1 || (s[j+1] == '0' && k-j > 1) || atoi(s.substr(j+1, k-j).c_str()) > 255)
				{
					/* code */
					continue;
				}
				if ((s.length()-k == 2 || s[k+1] != '0') && atoi(s.substr(k+1).c_str()) <= 255)
				{
					/* code */
					string temp = s.substr(0, i+1)+"."+s.substr(i+1, j-i)+"."+s.substr(j+1, k-j)+"."+s.substr(k+1);
					res.push_back(temp);
				}
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	string s = "010010";
	vector<string> res = restoreIpAddresses(s);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}