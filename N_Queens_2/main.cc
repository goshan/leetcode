#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;






void solve(int row, int rd, int ld, int &res, int final){
	if (row == final)
	{
		/* code */
		res ++;
		return;
	}
	int pos = final & (~ (row | rd | ld));
	while (pos != 0){
		int p = pos & (-pos);
		pos -= p;
		solve(row+p, (rd+p)>>1, (ld+p)<<1, res, final);
	}
}

int totalNQueens(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int res = 0;
	int final = (1<<n)-1;
	solve(0, 0, 0, res, final);
	return res;
}



int main(int argc, char const *argv[])
{
	/* code */
	cout <<totalNQueens(8) <<endl;
	return 0;
}