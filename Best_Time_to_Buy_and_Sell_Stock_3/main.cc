#include <iostream>
#include <vector>
using namespace std;





int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (prices.size() == 0)
	{
		/* code */
		return 0;
	}
	vector<int> fro_max_sub = vector<int>(prices.size(), 0);
	vector<int> fro_min = vector<int>(prices.size(), 0);
	vector<int> bac_max_sub = vector<int>(prices.size(), 0);
	vector<int> bac_max = vector<int>(prices.size(), 0);
	fro_min[0] = prices[0];
	fro_max_sub[0] = 0;
	bac_max[prices.size()-1] = prices[prices.size()-1];
	bac_max_sub[prices.size()-1] = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		/* code */
		fro_min[i] = prices[i] < fro_min[i-1] ? prices[i] : fro_min[i-1];
		fro_max_sub[i] = prices[i]-fro_min[i] > fro_max_sub[i-1] ? prices[i]-fro_min[i] : fro_max_sub[i-1];

		int j = prices.size()-1-i;
		bac_max[j] = prices[j] > bac_max[j+1] ? prices[j] : bac_max[j+1];
		bac_max_sub[j] = bac_max[j]-prices[j] > bac_max_sub[j+1] ? bac_max[j]-prices[j] : bac_max_sub[j+1];
	}

	int max = 0;
	for (int i = 0; i < prices.size()-1; ++i)
	{
		/* code */
		int temp = fro_max_sub[i]+bac_max_sub[i+1];
		if (temp > max)
		{
			/* code */
			max = temp;
		}
	}
	if (fro_max_sub[prices.size()-1] > max)
	{
		/* code */
		max = fro_max_sub[prices.size()-1];
	}
	if (bac_max_sub[0] > max)
	{
		/* code */
		max = bac_max_sub[0];
	}
	return max;
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