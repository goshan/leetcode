#include <iostream>
#include <string>
using namespace std;





//regular: \\s*[+|-]?[0-9]*\.?[0-9]*[e[+|-]?[0-9]+]?\s*\
//state:     0   1     2  31|32 4    5  6     7      8
//          31(no digtal before)|32(yes) 
//final:               t     t  t             t      t
bool isNumber(const char *s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int state = 0;
	int i = 0;
	while (s[i] != '\0'){
		char c = s[i];
		switch (state)
		{
			/* code */
			case 0:
			if (c == ' ') ;
			else if (c == '+' || c == '-') state = 1;
			else if (c <= '9' && c >= '0') state = 2;
			else if (c == '.') state = 31;
			else return false;
			break;
			case 1:
			if (c <= '9' && c >= '0') state = 2;
			else if (c == '.') state = 31;
			else return false;
			break;
			case 2:
			if (c <= '9' && c >= '0') ;
			else if (c == '.') state = 32;
			else if (c == 'e') state = 5;
			else if (c == ' ') state = 8;
			else return false;
			break;
			case 31:
			if (c <= '9' && c >= '0') state = 4;
			else return false;
			break;
			case 32:
			if (c <= '9' && c >= '0') state = 4;
			else if (c == 'e') state = 5;
			else if (c == ' ') state = 8;
			else return false;
			break;
			case 4:
			if (c <= '9' && c >= '0') ;
			else if (c == 'e') state = 5;
			else if (c == ' ') state = 8;
			else return false;
			break;
			case 5:
			if (c == '+' || c == '-') state = 6;
			else if (c <= '9' && c >= '0') state = 7;
			else return false;
			break;
			case 6:
			if (c <= '9' && c >= '0') state = 7;
			else return false;
			break;
			case 7:
			if (c <= '9' && c >= '0') ;
			else if (c == ' ') state = 8;
			else return false;
			break;
			case 8:
			if (c == ' ') ;
			else return false;
			break;
		}
		i++;
	}
	if (state == 2 || state == 32|| state == 4 || state == 7 || state == 8)
	{
		/* code */
		return true;
	}
	else {
		return false;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	string s = "2e+0";
	cout <<isNumber(s.c_str()) <<endl;
	return 0;
}