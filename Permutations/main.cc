#include <iostream>
#include <map>
#include <vector>
using namespace std;








void per(int index, int length, map<int, int> &cache, vector<int> elem, vector<vector<int> > &res){
	if (index == length)
	{
		/* code */
		res.push_back(elem);
		return;
	}
	for (map<int, int> ::iterator it = cache.begin(); it != cache.end(); it++)
	{
		/* code */
		if (it ->second != 0)
		{
			/* code */
			elem.push_back(it ->first);
			it ->second --;
			per(index+1, length, cache, elem, res);
			elem.pop_back();
			it ->second ++;
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> >res;
	if (num.size() == 0)
	{
		/* code */
		return res;
	}
	vector<int> elem;
	map<int, int> cache;
	for (int i = 0; i < num.size(); ++i)
	{
		/* code */
		if (cache.count(num[i]))
		{
			/* code */
			cache[num[i]] ++;
		}
		else {
			cache[num[i]] = 1;
		}
	}
	per(0, num.size(), cache, elem, res);
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > res = permute(num);
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