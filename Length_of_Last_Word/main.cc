#include <iostream>
#include <string>
using namespace std;




int lengthOfLastWord(const char *s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i = 0;
	int start = -1;
	int last_length = 0;
	while (s[i] != '\0'){
		if (s[i] == ' ')
		{
			/* code */
			int length = i-start-1;
			if (length != 0)
			{
				/* code */
				last_length = length;
			}
			start = i;
		}
		i++;
	}
	int length = i-start-1;
	if (length != 0)
	{
		/* code */
		last_length = length;
	}
	return last_length;
}


int main(int argc, char const *argv[])
{
	/* code */
	string s = "Hello World ";
	cout <<lengthOfLastWord(s.c_str()) <<endl;
	return 0;
}