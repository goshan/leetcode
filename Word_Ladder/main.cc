#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;





void add_one_step(string current, set<string> &dict, queue<string> &cache, map<string, int> &path){
	int length = path[current];
	for (int i = 0; i < current.length(); ++i)
	{
		/* code */
		char t_c = current[i];
		for (char c = 'a'; c <= 'z'; c++){
			current[i] = c;
			if (dict.count(current))
			{
				/* code */
				dict.erase(current);
				cache.push(current);
				path[current] = length + 1;
			}
		}
		current[i] = t_c;
	}
}


int ladderLength(string start, string end, set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	map<string, int> path;
	path[start] = 1;
	if (dict.count(start))
	{
		/* code */
		dict.erase(start);
	}
	queue<string> cache;
	cache.push(start);
	while (cache.size() != 0){
		string temp = cache.front();
		cache.pop();
		if (temp == end)
		{
			/* code */
			return path[temp];
		}
		add_one_step(temp, dict, cache, path);
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	/* code */
	string start = "hit";
	string end = "cog";
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	dict.insert("cog");
	cout <<ladderLength(start, end, dict) <<endl;
	return 0;
}