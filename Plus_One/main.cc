#include <iostream>
#include <vector>
using namespace std;







vector<int> plusOne(vector<int> &digits) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	digits[digits.size()-1] += 1;
	int pos = digits.size()-1;
	while (digits[pos] > 9){
		digits[pos] -= 10;
		if (pos == 0)
		{
			/* code */
			digits.push_back(0);
			for (int i = digits.size()-1; i >= 1; --i)
			{
				/* code */
				digits[i] = digits[i-1];
			}
			digits[0] = 1;
			break;
		}
		else {
			pos --;
			digits[pos] += 1;
		}
	}
	return digits;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> d;
	d.push_back(8);
	d.push_back(9);
	d.push_back(9);
	d.push_back(9);
	vector<int> res = plusOne(d);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<" ";
	}
	cout <<endl;
	return 0;
}