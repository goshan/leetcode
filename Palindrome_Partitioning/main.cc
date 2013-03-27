#include <iostream>
#include <vector>
using namespace std;



vector<vector<string> > minCut(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function 
	int n = s.size();
	vector<vector<vector<string> > > res(n+1, vector<vector<string> >());
	vector<string> last(1, s.substr(n-1, 1));
	res[n-1].push_back(last);
	vector<vector<bool> > p(n, vector<bool>(n, false));  
	for(int i = n - 2; i >=0; --i){
		for(int j = i; j < n; ++j){
			if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])){
				p[i][j] = true;
				vector<vector<string> > temp = res[j+1];
				if (temp.size() == 0)
				{
					/* code */
					res[i].push_back(vector<string>(1, s.substr(i, j-i+1)));
				}
				else {
					for (int k = 0; k < temp.size(); ++k)
					{
						/* code */
						temp[k].push_back(s.substr(i, j-i+1));
						res[i].push_back(temp[k]);
					}
				}
			}
		}
	}
	vector<vector<string> > result;
	for (int i = 0; i < res[0].size(); ++i)
	{
		/* code */
		vector<string> temp;
		for (int j = res[0][i].size()-1; j >= 0 ; --j)
		{
			/* code */
			temp.push_back(res[0][i][j]);
		}
		result.push_back(temp);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	while (1){
		string s = "";
		cin >>s;
		vector<vector<string> >res = minCut(s);
		for (int i = 0; i < res.size(); ++i)
		{
			/* code */
			for (int j = 0; j < res[i].size(); ++j)
			{
				/* code */
				cout <<res[i][j] <<" ";
			}
			cout <<endl;
		}
	}
	return 0;
}