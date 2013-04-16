#include <iostream>
#include <vector>
using namespace std;






void generate(int n, int stack, string s, vector<string> &res){
	if (n == 0)
	{
		/* code */
		res.push_back(s);
		s = "";
		return;
	}
	else if (stack == 0)
	{
		/* code */
		generate(n, stack+1, s+"(", res);
	}
	else if (stack == n)
	{
		/* code */
		generate(n-1, stack-1, s+")", res);
	}
	else {
		generate(n, stack+1, s+"(", res);
		generate(n-1, stack-1, s+")", res);
	}
}

vector<string> generateParenthesis(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<string> res;
	string s = "";
	int stack = 0;
	generate(n, stack, s, res);
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<string> res = generateParenthesis(3);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}