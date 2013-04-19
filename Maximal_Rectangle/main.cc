#include <iostream>
#include <vector>
using namespace std;





int maximalRectangle(vector<vector<char> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int maxArea = 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		for (int j=0; j<matrix[i].size(); j++){
			int minX = matrix[i].size();
			for (int k=i; k<matrix.size(); k++){
				if (matrix[k][j] == '0')
				{
					/* code */
					break;
				}
				for (int l=j; l<minX; l++){
					if (matrix[k][l] == '0')
					{
						/* code */
						minX = l;
						break;
					}
				}
				int area = (k-i+1)*(minX-j);
				if (area > maxArea)
				{
					/* code */
					maxArea = area;
				}
			}
		}
	}
	return maxArea;
}

int main(int argc, char const *argv[])
{
	/* code */
	int temp[3][5] = {{'0', '1', '1', '1', '0'}, {'0', '1', '1', '1', '1'}, {'0', '0', '1', '0', '1'}};
	vector<vector<char> > input;
	for (int i = 0; i < 3; ++i)
	{
		/* code */
		vector<char> elem;
		for (int j=0; j<5; j++){
			elem.push_back(temp[i][j]);
		}
		input.push_back(elem);
	}
	cout <<maximalRectangle(input) <<endl;
	return 0;
}