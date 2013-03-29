#include <iostream>
#include <vector>
using namespace std;






int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int max_sub = 0;
	int min = 1000000;
	for (int i = 0; i < prices.size(); ++i)
	{
		/* code */
		if (prices[i]-min > max_sub)
		{
			/* code */
			max_sub = prices[i]-min;
		}
		if (prices[i] < min)
		{
			/* code */
			min = prices[i];
		}
	}
	return max_sub;
}

int main(int argc, char const *argv[])
{
	/* code */
	int num;
	cin >>num;
	vector<int> prices;
	for (int i = 0; i < num; ++i)
	{
		/* code */
		int n;
		cin >>n;
		prices.push_back(n);
	}
	cout <<maxProfit(prices) <<endl;
	return 0;
}