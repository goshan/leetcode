#include <iostream>
#include <vector>
using namespace std;






// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *com_sortedArrayToBST(const vector<int> &num, int start, int end) {
	if (start == end-1)
	{
		/* code */
		return new TreeNode(num[start]);
	}
	int mid = (end-start)/2+start;
	TreeNode *root = new TreeNode(num[mid]);
	if (mid == end-1)
	{
		/* code */
		root ->left = com_sortedArrayToBST(num, start, mid);
		root ->right = NULL;
	}
	else {
		root ->left = com_sortedArrayToBST(num, start, mid);
		root ->right = com_sortedArrayToBST(num, mid+1, end);
	}
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (num.size() == 0)
	{
		/* code */
		return NULL;
	}
	return com_sortedArrayToBST(num, 0, num.size());
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	TreeNode *head = sortedArrayToBST(num);
	cout <<head ->val <<endl;
	return 0;
}