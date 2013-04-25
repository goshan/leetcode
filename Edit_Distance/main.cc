#include <iostream>
#include <vector>
#include <string>
using namespace std;




int minDistance(string word1, string word2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > dis(word1.length()+1, vector<int> (word2.length()+1, 0));
	dis[0][0] = 0;
	for (int i = 1; i < dis.size(); ++i)
	{
		/* code */
		dis[i][0] = i;
	}
	for (int i = 1; i < dis[0].size(); ++i)
	{
		/* code */
		dis[0][i] = i;
	}
	for (int i = 1; i < dis.size(); ++i)
	{
		/* code */
		for (int j=1; j<dis[i].size(); j++){
			int temp = word1[i-1] == word2[j-1] ? dis[i-1][j-1] : dis[i-1][j-1]+1;
			dis[i][j] = min(dis[i-1][j], dis[i][j-1]);
			dis[i][j] = min(dis[i][j]+1, temp);
		}
	}
	return dis.back().back();
}


int main(int argc, char const *argv[])
{
	/* code */
	string s1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
	string s2 = "ultramicroscopically";
	cout <<minDistance(s1, s2) <<endl;
	return 0;
}