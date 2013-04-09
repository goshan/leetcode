#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;




vector<vector<int> > road;
vector<string> dict_con;
map<string, int> id;

void build_road(set<string> &dict){
	for (set<string> ::const_iterator it=dict.begin(); it!=dict.end(); it++){
		id[*it] = dict_con.size();
		dict_con.push_back(*it);
		road.push_back(vector<int> (dict.size(), 0));
	}
	for (int i = 0; i < dict_con.size(); ++i)
	{
		/* code */
		string current = dict_con[i];
		for (int j = 0; j < current.length(); ++j)
		{
			/* code */
			char t_c = current[j];
			for (char c = 'a'; c <= 'z'; c++){
				if (c == t_c)
				{
					/* code */
					continue;
				}
				current[j] = c;
				if (id.count(current))
				{
					/* code */
					road[i][id[current]] = 1;
				}
			}
			current[j] = t_c;
		}
	}
}

void gen_res(int e, int s, const vector<vector<int> > &parents, vector<vector<string> > &res, vector<int> temp_path){
	if (e == s)
	{
		/* code */
		vector<string> elem;
		elem.push_back(dict_con[s]);
		for (int i = temp_path.size()-1; i >= 0; --i)
		{
			/* code */
			elem.push_back(dict_con[temp_path[i]]);
		}
		res.push_back(elem);
		temp_path.clear();
		return;
	}
	temp_path.push_back(e);
	for (int i = 0; i < parents[e].size(); ++i)
	{
		/* code */
		gen_res(parents[e][i], s, parents, res, temp_path);
	}
}


vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	build_road(dict);
	int level = 1;
	int current_num = 1;
	int next_num = 0;
	bool final_level = false;
	int s = id[start];
	int e = id[end];
	queue<int> cache;
	cache.push(s);
	vector<vector<int> > parents(dict.size());
	vector<int> dis(dict.size(), 1000000);
	while (cache.size() != 0){
		int temp = cache.front();
		cache.pop();
		current_num --;
		if (temp == e)
		{
			/* code */
			final_level = true;
		}
		else {
			vector<int> child = road[temp];
			for (int i = 0; i < child.size(); ++i)
			{
				/* code */
				if (child[i] == 1 && level <= dis[i])
				{
					/* code */
					if (level < dis[i])
					{
						/* code */
						parents[i].clear();
					}
					dis[i] = level;
					next_num ++;
					parents[i].push_back(temp);
					cache.push(i);
					road[i][temp] = 0;
				}
			}
		}

		if (current_num == 0)
		{
			/* code */
			level ++;
			current_num = next_num;
			next_num = 0;
			if (final_level)
			{
				/* code */
				break;
			}
		}
	}

	vector<vector<string> >res;
	vector<int> temp_path;
	gen_res(e, s, parents, res, temp_path);
	return res;
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