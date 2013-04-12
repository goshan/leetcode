#include <iostream>
using namespace std;




// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void order_detect(TreeNode *root, TreeNode *&prev, TreeNode *&err1, TreeNode *&err2){
	if (root == NULL)
	{
		/* code */
		return;
	}
	order_detect(root ->left, prev, err1, err2);
	if (prev != NULL && prev ->val > root ->val)
	{
		/* code */
		err2 = root;
		if (err1 == NULL)
		{
			/* code */
			err1 = prev;
		}
	}
	prev = root;
	order_detect(root ->right, prev, err1, err2);
}

void recoverTree(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	TreeNode *prev = NULL;
	TreeNode *err1 = NULL;
	TreeNode *err2 = NULL;
	order_detect(root, prev, err1, err2);
	if (err1 != NULL && err2 != NULL)
	{
		/* code */
		swap(err1 ->val, err2 ->val);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(2);
	TreeNode right(1);
	TreeNode right1(3);
	right.right = &right1;
	root.right = &right;
	recoverTree(&root);
	cout <<root.val <<endl;
	cout <<right.val <<endl;
	cout <<right1.val <<endl;
	return 0;
}