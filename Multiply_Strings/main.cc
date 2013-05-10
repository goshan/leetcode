#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;






string multiply(string num1, string num2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> n1(num1.length(), 0);
	for (int i = 0; i < num1.length(); ++i)
	{
		/* code */
		n1[num1.length()-i-1] = num1[i]-'0';
	}
	vector<int> n2(num2.length(), 0);
	for (int i = 0; i < num2.length(); ++i)
	{
		/* code */
		n2[num2.length()-i-1] = num2[i]-'0';
	}
	vector<int> n(n1.size()+n2.size(), 0);
	for (int j=0; j<n1.size(); j++){
		for (int k=0; k<n2.size(); k++){
			n[j+k] += n1[j]*n2[k];
		}
	}
	for (int i = 0; i < n.size(); i++)
	{
		/* code */
		n[i+1] += n[i]/10;
		n[i] %= 10;
	}
	int len = n.size()-1;
	for (; len >=0; --len)
	{
		/* code */
		if (n[len] != 0)
		{
			/* code */
			break;
		}
	}
	len = len == -1 ? 0 : len;
	stringstream ss;
	for (int i = len; i >= 0; --i)
	{
		/* code */
		ss <<n[i];
	}
	return ss.str();
}


int main(int argc, char const *argv[])
{
	/* code */
	string num1 = "98";
	string num2 = "9";
	string res = multiply(num1, num2);
	cout <<"======" <<res <<"=====" <<endl;
	return 0;
}