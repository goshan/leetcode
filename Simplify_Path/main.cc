#include <iostream>
#include <string>
#include <vector>
using namespace std;




string simplifyPath(string path) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<string> cache;
	int start = 0;
	for (int i = 0; i <= path.length(); ++i)
	{
		/* code */
		if (path[i] == '/' || i == path.length())
		{
			/* code */
			string file = path.substr(start, i-start);
			if (file == "")
			{
				/* code */
			}
			else if (file == ".")
			{
				/* code */
			}
			else if (file == "..")
			{
				/* code */
				if (cache.size() != 0)
				{
					/* code */
					cache.pop_back();
				}
			}
			else {
				cache.push_back(file);
			}
			start = i+1;
		}
	}
	string res = "";
	for (int i = 0; i < cache.size(); ++i)
	{
		/* code */
		res += "/"+cache[i];
	}
	if (res == "")
	{
		/* code */
		return "/";
	}
	else {
		return res;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	string path = "/.home";
	cout <<simplifyPath(path) <<endl;
	return 0;
}