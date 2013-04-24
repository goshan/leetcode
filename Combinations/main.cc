#include <iostream>
#include <vector>
using namespace std;






vector<vector<int> > combine(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > res;
	if (k == 1)
	{
		/* code */
		for (int i = 0; i < n; ++i)
		{
			/* code */
			vector<int> elem(1, i+1);
			res.push_back(elem);
		}
		return res;
	}
	else if (n == k)
	{
		/* code */
		vector<int> elem;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			elem.push_back(i+1);
		}
		res.push_back(elem);
		return res;
	}
	vector<vector<int> > n_1_k_1 = combine(n-1, k-1);
	res = combine(n-1, k);
	for (int i = 0; i < n_1_k_1.size(); ++i)
	{
		/* code */
		n_1_k_1[i].push_back(n);
		res.push_back(n_1_k_1[i]);
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int> > res = combine(4, 2);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		for (int j=0; j<res[i].size(); j++){
			cout <<res[i][j] <<" ";
		}
		cout <<endl;
	}
	return 0;
}