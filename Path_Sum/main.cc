#include <iostream>
using namespace std;






struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL)
	{
		/* code */
		return false;
	}
	if (root ->left == NULL && root ->right == NULL)
	{
		/* code */
		return root ->val == sum;
	}
	if (root ->left != NULL)
	{
		/* code */
		root ->left ->val += root ->val;
		if (hasPathSum(root ->left, sum))
		{
			/* code */
			return true;
		}
	}
	if (root ->right != NULL)
	{
		/* code */
		root ->right ->val += root ->val;
		if (hasPathSum(root ->right, sum))
		{
			/* code */
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}