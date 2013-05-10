#include <iostream>
#include <string>
#include <vector>
using namespace std;





bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int slength = 0;
	while (s[slength] != '\0') slength ++;
	int plength = 0;
	while (p[plength] != '\0') plength ++;
	vector<bool> match(slength+1, false);
	match[0] = true;
	while (*p != '\0')
	{
		/* code */
		if (*p == '*')
		{
			/* code */
			while (*p == '*'){
				p ++;
			}
			p--;
			int last = match[0];
			int i = 1;
			for (; i<match.size(); i++){
				int current = match[i];
				if (last || current)
				{
					/* code */
					break;
				}
				else {
					match[i] = false;
				}
				last = current;
			}
			for (; i < match.size(); ++i)
			{
				/* code */
				match[i] = true;
			}
		}
		else {
			int last = match[0];
			match[0] = false;
			for (int i = 1; i < match.size(); ++i)
			{
				/* code */
				int current = match[i];
				if (*p == '?' || *p == s[i-1])
				{
					/* code */
					match[i] = last;
				}
				else {
					match[i] = false;
				}
				last = current;
			}
		}
		p++;
	}
	return match.back();
}


int main(int argc, char const *argv[])
{
	/* code */
	string s = "aa";
	string p = "aa";
	cout <<isMatch(s.c_str(), p.c_str()) <<endl;
	return 0;
}