#include <iostream>
#include <vector>
using namespace std;




int get_minCut_std(string s) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    int n = s.size();  
    vector<int > res(n+1);  
    vector<vector<bool> > p(n, vector<bool>(n, false));  
    for(int i = 0 ;i <= n; ++i){  
        res[i] = n - i;  
    }  
    for(int i = n - 1; i >=0; --i){  
        for(int j = i; j < n; ++j){  
            if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])){  
                p[i][j] = true;  
                res[i] = min(res[i], res[j + 1] + 1);  
            }  
        }  
    }  
    return res[0] - 1;  
}  

int get_minCut_self(string s, int start, vector<vector<bool> > &p) {
	if (start >= s.length()-1)
	{
		/* code */
		return 0;
	}
	int min = 100000;
	for (int i = start; i < s.length(); ++i)
	{
		/* code */
		if (s[i] == s[start] && (i-start<2 || p[start+1][i-1]))
		{
			/* code */
			p[start][i] = true;
			int add_cuts = 1;
			if (i == s.length()-1)
			{
				/* code */
				add_cuts = 0;
			}
			int temp = get_minCut(s, i+1, p)+add_cuts;
			if (temp < min)
			{
				/* code */
				min = temp;
			}
		}
	}
	return min;
}

int minCut(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function 
	vector<vector<bool> > p(s.length(), vector<bool> (s.length(), false));
	return get_minCut(s, 0, p);
}

int main(int argc, char const *argv[])
{
	while (1){
		string s = "";
		cin >>s;
		cout <<minCut(s) <<endl;
	}
	return 0;
}