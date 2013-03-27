#include <iostream>
#include <vector>
#include <map>
using namespace std;





int get_consecutive(map<int, int> &table, int num, bool asc){
	int count = 0;
	if (asc)
	{
		/* code */
		while (table.count(num+1)){
			count ++;
			num ++;
			table.erase(num);
		}
	}
	else {
		while (table.count(num-1)){
			count ++;
			num --;
			table.erase(num);
		}
	}
	return count;
}

int longestConsecutive(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	map<int, int> table;
	for (int i = 0; i < num.size(); ++i)
	{
		/* code */
		table[num[i]] = num[i];
	}
	int max = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		/* code */
		if (table.count(num[i]))
		{
			/* code */
			int con = get_consecutive(table, num[i], false)+get_consecutive(table, num[i], true)+1;
			if (con > max)
			{
				/* code */
				max = con;
			}
		}
	}
	return max;
}


int main(int argc, char const *argv[])
{
	/* code */
	int n;
	vector<int> num;
	while (cin >>n){
		if (n == 0)
		{
			/* code */
			break;
		}
		num.push_back(n);
	}
	cout <<longestConsecutive(num) <<endl;
	return 0;
}