#include <iostream>
#include <string>
#include <vector>
using namespace std;






bool isInterleave(string s1, string s2, string s3){
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<bool> > interleave (s1.length()+1, vector<bool>(s2.length()+1, false));
	interleave[0][0] = true;
	for (int i = 0; i < s1.length(); ++i)
	{
		/* code */
		if (s1[i] == s3[i])
		{
			/* code */
			interleave[i+1][0] = true;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < s2.length(); ++i)
	{
		/* code */
		if (s2[i] == s3[i])
		{
			/* code */
			interleave[0][i+1] = true;
		}
		else {
			break;
		}
	}

	for (int i = 1; i < interleave.size(); ++i)
	{
		/* code */
		for (int j=1; j<interleave[i].size(); j++){
			interleave[i][j] = (interleave[i][j-1] && s2[j-1] == s3[i+j-1]) || (interleave[i-1][j] && s1[i-1] == s3[i+j-1]);
		}
	}
	return interleave.back().back();
}

int main(int argc, char const *argv[])
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout <<isInterleave(s1, s2, s3) <<endl;
	s3 = "aadbbbaccc";
	cout <<isInterleave(s1, s2, s3) <<endl;
	return 0;
}