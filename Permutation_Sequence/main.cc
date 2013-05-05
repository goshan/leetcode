#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <string>
using namespace std;








string sub_permutation(set<int> &candidate, int k, vector<int> &factorial){
	int n = candidate.size();
	if (n == 0)
	{
		/* code */
		return "";
	}
	int sum = 0;
	for (set<int> ::iterator it = candidate.begin(); it != candidate.end(); it++){
		if (sum+factorial[n-1] >= k)
		{
			/* code */
			int bit = *it;
			candidate.erase(*it);
			stringstream ss;
			ss <<bit <<sub_permutation(candidate, k-sum, factorial);
			return ss.str();
		}
		sum += factorial[n-1];
	}
	return "";
}

string getPermutation(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> factorial(10, 0);
	factorial[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		factorial[i] = factorial[i-1]*i;
	}
	set<int> candidate;
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		candidate.insert(i);
	}
	return sub_permutation(candidate, k, factorial);
}


int main(int argc, char const *argv[])
{
	/* code */
	cout <<getPermutation(3, 4) <<endl;
	return 0;
}