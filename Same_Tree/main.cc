#include <iostream>
using namespace std;





// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (p == NULL && q == NULL)
	{
		/* code */
		return true;
	}
	else if (p == NULL && q != NULL)
	{
		/* code */
		return false;
	}
	else if (p != NULL && q == NULL){
		return false;
	}
	else if (p ->val != q ->val)
	{
		/* code */
		return false;
	}
	return isSameTree(p ->left, q ->left) && isSameTree(p ->right, q ->right);
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root1(1);
	TreeNode left1(2);
	TreeNode right1(3);
	root1.left = &left1;
	root1.right = &right1;

	TreeNode root2(1);
	TreeNode left2(2);
	TreeNode right2(3);
	root2.left = &left2;
	root2.right = &right2;

	cout <<isSameTree(&root1, &root2) <<endl;
	return 0;
}