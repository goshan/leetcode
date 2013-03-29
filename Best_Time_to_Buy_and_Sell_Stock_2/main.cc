#include <iostream>
#include <vector>
using namespace std;






int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int sum = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		/* code */
		if (prices[i]-prices[i-1] > 0)
		{
			/* code */
			sum += prices[i]-prices[i-1];
		}
	}
	return sum;
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