#include <iostream>
#include <vector>
using namespace std;






void generate(int n, int stack, string s, vector<string> &res){
	cout <<n <<endl;
	cout <<stack <<endl;
	cout <<s <<endl;
	cout <<"=======" <<endl;
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

vector<string> generateParentheses(int n){
	vector<string> res;
	string s = "";
	int stack = 0;
	generate(n, stack, s, res);
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<string> res = generateParentheses(5);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}