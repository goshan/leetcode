#include <iostream>
#include <vector>
#include <stack>
using namespace std;





int largestRectangleArea(vector<int> &height) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int i = 0;
	int maxArea = 0;
	stack<int> pos;
	height.push_back(0);
	while (i < height.size()){
		if (pos.empty() || height[i] >= height[pos.top()])
		{
			/* code */
			pos.push(i);
			i ++;
		}
		else {
			int temp = pos.top();
			pos.pop();
			int area = height[temp]*(pos.empty() ? i : i-pos.top()-1);
			if (area > maxArea)
			{
				/* code */
				maxArea = area;
			}
		}
	}
	return maxArea;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);
	cout <<largestRectangleArea(height) <<endl;
	return 0;
}