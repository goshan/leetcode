#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;








// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> &intervals) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<char> > inter_gram;
	for (int i = 0; i < intervals.size(); ++i)
	{
		/* code */
		if (intervals[i].end >= inter_gram.size())
		{
			/* code */
			int size = inter_gram.size();
			for (int j=0; j<intervals[i].end-size+1; j++){
				inter_gram.push_back(vector<char> (0));
			}
		}
		inter_gram[intervals[i].start].push_back('s');
		inter_gram[intervals[i].end].push_back('e');
	}
	for (int i = 0; i < inter_gram.size(); ++i)
	{
		/* code */
		if (inter_gram[i].size() > 1)
		{
			/* code */
			sort(inter_gram[i].begin(), inter_gram[i].end());
		}
	}
	vector<int> pos;
	vector<int> stack;
	vector<char> dir;
	int sta = 0;
	for (int i = 0; i < inter_gram.size(); ++i)
	{
		/* code */
		if (inter_gram[i].size() == 0)
		{
			/* code */
			continue;
		}
		while (inter_gram[i].size()!=0){
			char c = inter_gram[i].back();
			inter_gram[i].pop_back();
			if (c == 's')
			{
				/* code */
				pos.push_back(i);
				stack.push_back(sta);
				sta ++;
				dir.push_back('s');
			}
			else if (c == 'e')
			{
				/* code */
				pos.push_back(i);
				sta --;
				stack.push_back(sta);
				dir.push_back('e');
			}
		}
	}
	vector<Interval> res;
	Interval temp;
	for (int i = 0; i < pos.size(); ++i)
	{
		/* code */
		if (stack[i] == 0 && dir[i] == 's')
		{
			/* code */
			temp.start = pos[i];
		}
		else if (stack[i] == 0 && dir[i] == 'e')
		{
			/* code */
			temp.end = pos[i];
			res.push_back(temp);
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<Interval> intervals;
	Interval a(1, 3);
	Interval b(2, 6);
	Interval c(8, 10);
	Interval d(15, 18);
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	vector<Interval> res = merge(intervals);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i].start <<" " <<res[i].end <<endl;
	}
	return 0;
}