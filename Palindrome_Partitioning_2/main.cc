#include <iostream>
#include <vector>
using namespace std;




int minCut(string s) {  
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

int main(int argc, char const *argv[])
{
	while (1){
		string s = "";
		cin >>s;
		cout <<minCut(s) <<endl;
	}
	return 0;
}