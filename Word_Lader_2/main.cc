#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;




struct path{
	struct path *prev;
	string current;
	int dis;
};

bool is_dis_one(string a, string b){
	int count = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		/* code */
		if (a[i] != b[i])
		{
			/* code */
			if (++count > 1)
			{
				/* code */
				return false;
			}
		}
	}
	if (count == 0){
		return false;
	}
	return true;
}

vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	queue<struct path *> active;
	vector<struct path *> res;
	set<string> visited;

	struct path *s = new struct path;
	s ->prev = NULL;
	s ->current = start;
	s ->dis = 1;
	active.push(s);
	int min = 1000000;

	while (active.size() != 0){
		struct path *p = active.front();
		active.pop();
		visited.insert(p ->current);
		if (p ->dis > min){
			continue;
		}

		if (is_dis_one(p ->current, end))
		{
			/* code */
			struct path *fin = new struct path;
			fin ->current = end;
			fin ->prev = p;
			fin ->dis = p ->dis+1;
			res.push_back(fin);
			if (fin ->dis < min){
				min = fin ->dis;
			}
			continue;
		}

		for (set <string> ::iterator it=dict.begin(); it!=dict.end(); it++){
			if (!visited.count(*it) && is_dis_one(p ->current, *it))
			{
				/* code */
				struct path *next = new struct path;
				next ->prev = p;
				next ->current = *it;
				next ->dis = p ->dis+1;
				active.push(next);
			}
		}
	}

	vector<vector<string> > ladders;
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		if (res[i] ->dis > min){
			continue;
		}
		vector<string> elem;
		struct path *p = res[i];
		while (p != NULL){
			elem.push_back(p ->current);
			p = p ->prev;
		}
		vector<string> temp;
		for (int j = elem.size()-1; j >= 0; j--)
		{
			/* code */
			temp.push_back(elem[j]);
		}
		ladders.push_back(temp);
	}
	return ladders;
}

int main(int argc, char const *argv[])
{
	/* code */
	string start = "hit";
	string end = "cog";
	set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("hit");
	dict.insert("lot");
	dict.insert("log");
	vector<vector<string> > res = findLadders(start, end, dict);
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