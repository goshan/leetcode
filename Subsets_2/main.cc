#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;






void search_behind(vector<int> s, int start, vector<int> &elem, vector<vector<int> > &res){
	res.push_back(elem);
	for (int i = start; i < s.size(); ++i)
	{
		/* code */
		elem.push_back(s[i]);
		search_behind(s, i+1, elem, res);
		elem.pop_back();
	}
}

vector<vector<int> > subsets(vector<int> &S) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > res;
	vector<int> elem;
	sort(S.begin(), S.end());
	search_behind(S, 0, elem, res);
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	vector<vector<int> > res = subsets(S);
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