#include <iostream>
#include <vector>
using namespace std;






void con_index(int index, int start, int end, int &row, int &col){
	int length = end-start+1;
	int seg = index/length;
	switch(seg){
		case 0:
		row = start;
		col = start+index;
		break;
		case 1:
		row = start+index%length;
		col = end;
		break;
		case 2:
		row = end;
		col = end-index%length;
		break;
		case 3:
		row = end-index%length;
		col = start;
		break;
	}
}


void rotate_edge(vector<vector<int> > &matrix, int start, int end){
	if (end-start <= 0)
	{
		/* code */
		return;
	}
	int length = end-start+1;
	for (int i = 0; i < length-1; ++i)
	{
		/* code */
		int row1 = 0;
		int col1 = 0;
		con_index(i, start, end, row1, col1);
		int row2 = 0;
		int col2 = 0;
		con_index(i+length, start, end, row2, col2);
		swap(matrix[row1][col1], matrix[row2][col2]);
		con_index(i+2*length, start, end, row2, col2);
		swap(matrix[row1][col1], matrix[row2][col2]);
		con_index(i+3*length, start, end, row2, col2);
		swap(matrix[row1][col1], matrix[row2][col2]);
	}
	rotate_edge(matrix, start+1, end-1);
}


void rotate(vector<vector<int> > &matrix) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	rotate_edge(matrix, 0, matrix.size()-1);
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector<int> b;
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	vector<int> c;
	c.push_back(7);
	c.push_back(8);
	c.push_back(9);
	vector<vector<int> > matrix;
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	rotate(matrix);
	for (int i = 0; i < matrix.size(); ++i)
	{
		/* code */
		for (int j=0; j<matrix[i].size(); j++){
			cout <<matrix[i][j] <<" ";
		}
		cout <<endl;
	}
	return 0;
}