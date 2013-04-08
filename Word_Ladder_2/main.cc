#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;




struct path{
	string content;
	path *parent;
};

void add_one_step(path *current, set<string> &dict, queue<path *> &cache, int &next_num, vector<string> &level_used){
	string origin = current ->content;
	for (int i = 0; i < origin.length(); ++i)
	{
		/* code */
		char t_c = origin[i];
		for (char c = 'a'; c <= 'z'; c++){
			if (c == t_c)
			{
				/* code */
				continue;
			}
			origin[i] = c;
			if (dict.count(origin))
			{
				/* code */
				next_num ++;
				path *p = new path;
				p ->content = origin;
				p ->parent = current;
				cache.push(p);
				level_used.push_back(origin);
			}
		}
		origin[i] = t_c;
	}
}


vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<path *> final;
	int current_num = 1;
	int next_num = 0;
	bool final_level = false;
	vector<string> level_used;
	queue<path *> cache;
	path *s = new path;
	s ->content = start;
	s ->parent = NULL;
	cache.push(s);
	while (cache.size() != 0){
		path *temp = cache.front();
		cache.pop();
		current_num --;
		if (temp ->content == end)
		{
			/* code */
			final_level = true;
			final.push_back(temp);
		}
		else {
			add_one_step(temp, dict, cache, next_num, level_used);
		}

		if (current_num == 0)
		{
			/* code */
			for (int i = 0; i < level_used.size(); ++i)
			{
				/* code */
				dict.erase(level_used[i]);
			}
			level_used.clear();
			current_num = next_num;
			next_num = 0;
			if (final_level)
			{
				/* code */
				break;
			}
		}
	}
	vector<vector<string> > temp_res;
	for (int i = 0; i < final.size(); ++i)
	{
		/* code */
		path *p = final[i];
		vector<string> elem;
		while (p != NULL){
			elem.push_back(p ->content);
			p = p ->parent;
		}
		temp_res.push_back(elem);
	}
	vector<vector<string> > res;
	for (int i = 0; i < temp_res.size(); ++i)
	{
		/* code */
		vector<string> elem;
		/* code */
		for (int j=temp_res[i].size()-1; j>=0; j--){
			elem.push_back(temp_res[i][j]);
		}
		res.push_back(elem);
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	string start = "hot";
	string end = "dog";
	set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
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