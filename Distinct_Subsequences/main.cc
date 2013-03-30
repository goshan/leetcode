// dis[i][j]表示：T的前j个字符在S的前i个字符中出现的次数
// 如果S[i] == T[j]则 dis[i][j] = dis[i-1][j] + dis[i-1][j-1]
// 如果S[i] != T[j]则 dis[i][j] = dis[i-1][j]
// dis[0][0] = S[0] == T[0] ? 1 : 0
// dis[0][j] = 0
// dis[i][0] = S[i] == T[0] ? dis[i-1][0]+1 : dis[i-1][0]
// 注意：动归的是S的长度，而不是T的长度，如果动归T的长度，那么在S[i] != T[j]的情况下，S[0-i]同T[0-j-1]的结果不是都符合新的条件（S[i]同T[j-1]匹配的情况下）！




#include <iostream>
#include <string>
#include <vector>
using namespace std;





int numDistinct(string S, string T) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (S.length() == 0)
	{
		/* code */
		return 0;
	}
	else if (T.length() == 0)
	{
		/* code */
		return 1;
	}
	else if (S == T)
	{
		/* code */
		return 1;
	}
	vector<vector<int> > dis(S.length(), vector<int>(T.length(), 0));
	dis[0][0] = S[0] == T[0] ? 1 : 0;
	for (int i = 1; i < S.length(); ++i)
	{
		/* code */
		dis[i][0] = S[i] == T[0] ? dis[i-1][0]+1 : dis[i-1][0];
	}
	for (int i = 1; i < dis.size(); ++i)
	{
		/* code */
		for (int j=1; j<dis[i].size(); j++){
			dis[i][j] = S[i]==T[j] ? dis[i-1][j]+dis[i-1][j-1] : dis[i-1][j];
		}
	}
	return dis.back().back();
}

int main(int argc, char const *argv[])
{
	/* code */
	string S = "rabbbit";
	string T = "rabbit";
	cout <<numDistinct(S, T) <<endl;
	return 0;
}