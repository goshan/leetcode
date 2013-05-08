#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;









vector<string> anagrams(vector<string> &strs) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	map<string, vector<string> > groups;
	vector<string> res;
	for (int i = 0; i < strs.size(); ++i)
	{
		/* code */
		string temp = strs[i];
		sort(temp.begin(), temp.end());
		groups[temp].push_back(strs[i]);
	}
	for (map<string, vector<string> > ::const_iterator it = groups.begin(); it != groups.end(); it++){
		if (it ->second.size() > 1)
		{
			/* code */
			for (int i = 0; i < it ->second.size(); ++i)
			{
				/* code */
				res.push_back(it ->second[i]);
			}
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<string> strs;
	strs.push_back("aab");
	strs.push_back("aba");
	strs.push_back("acb");
	strs.push_back("abc");
	strs.push_back("bab");
	strs.push_back("baa");
	vector<string> res = anagrams(strs);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}