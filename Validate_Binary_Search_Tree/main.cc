#include <iostream>
using namespace std;




// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool order_detect(TreeNode *root, TreeNode *&prev){
	if (root == NULL)
	{
		/* code */
		return true;
	}
	if (!order_detect(root ->left, prev))
	{
		/* code */
		return false;
	}
	if (prev != NULL && prev ->val >= root ->val)
	{
		/* code */
		return false;
	}
	prev = root;
	return order_detect(root ->right, prev);
}

bool isValidBST(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	TreeNode *prev = NULL;
	return order_detect(root, prev);
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(1);
	TreeNode right(2);
	TreeNode right1(3);
	right.right = &right1;
	root.right = &right;
	cout <<isValidBST(&root) <<endl;
	return 0;
}