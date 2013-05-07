#include <iostream>
#include <string>
#include <vector>
using namespace std;








vector<string> output(int n, vector<int> sol){
	vector<string> res;
	int filter = 1<<(n-1);
	for (int i = 0; i < sol.size(); ++i)
	{
		/* code */
		string elem = "";
		for (int j=0; j<n; j++){
			int bit = (sol[i]<<j) & filter;
			elem += bit == filter ? "Q" : ".";
		}
		res.push_back(elem);
	}
	return res;
}



void solve(int row, int rd, int ld, vector<int> sol, vector<vector<string> > &res, int final, int n){
	if (row == final)
	{
		/* code */
		vector<string> elem = output(n, sol);
		res.push_back(elem);
		return;
	}
	int pos = final & (~ (row | rd | ld));
	while (pos != 0){
		int p = pos & (-pos);
		pos -= p;
		sol.push_back(p);
		solve(row+p, (rd+p)>>1, (ld+p)<<1, sol, res, final, n);
		sol.pop_back();
	}
}


vector<vector<string> > solveNQueens(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int final = (1<<n)-1;
	vector<int> sol;
	vector<vector<string> > res;
	solve(0, 0, 0, sol, res, final, n);
	return res;
}



int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<string> > res = totalNQueens(8);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		for (int j=0; j<res[i].size(); j++){
			cout <<res[i][j] <<endl;
		}
		cout <<endl;
	}
	cout <<res.size() <<endl;

	int a = 10;
	vector<int> aaa;
	aaa.push_back(a);
	vector<string> aa = output(4, aaa);
	for (int i = 0; i < aa.size(); ++i)
	{
		/* code */
		cout <<aa[i] <<endl;
	}
	return 0;
}