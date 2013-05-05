#include <iostream>
#include <vector>
using namespace std;








// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<Interval> res;
	bool merge = false;
	for (int i = 0; i < intervals.size(); ++i)
	{
		/* code */
		if (merge)
		{
			/* code */
			res.push_back(intervals[i]);
		}
		else if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].end)
		{
			// [3, 5] --> [2, 4] ==>  *[2, 5]
			/* code */
			newInterval.start = intervals[i].start;
		}
		else if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end && newInterval.start <= intervals[i].start)
		{
			// [3, 5] --> [4, 7] ==>  *[3, 7]
			/* code */
			newInterval.end = intervals[i].end;
		}
		else if (newInterval.start <= intervals[i].start && newInterval.end >= intervals[i].end)
		{
			// [3, 6] --> [4, 5] ==>  *[3, 6]
			/* code */
		}
		else if (newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end)
		{
			// [3, 6] --> [2, 7] ==> [2, 7]
			/* code */
			res.push_back(intervals[i]);
			merge = true;
		}
		else if (newInterval.end < intervals[i].start)
		{
			// [3, 5] --> [6, 8] ==> [3, 5] [6, 8]  *[3, 5]
			/* code */
			res.push_back(newInterval);
			res.push_back(intervals[i]);
			merge = true;
		}
		else {
			// [3, 5] --> [1, 2] ==> [1, 2]  *[3, 5]
			res.push_back(intervals[i]);
		}
	}
	if (!merge)
	{
		/* code */
		res.push_back(newInterval);
	}
	return res;
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<Interval> intervals;
	Interval a(1, 2);
	Interval b(3, 5);
	Interval c(6, 7);
	Interval d(8, 10);
	Interval e(12, 16);
	intervals.push_back(a);
	intervals.push_back(b);
	intervals.push_back(c);
	intervals.push_back(d);
	intervals.push_back(e);
	Interval newInterval(4, 9);
	vector<Interval> res = insert(intervals, newInterval);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i].start <<" " <<res[i].end <<endl;
	}
	return 0;
}