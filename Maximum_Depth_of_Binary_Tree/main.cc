#include <iostream>
using namespace std;



struct TreeNode
{
	/* data */
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_max(int a, int b){
	return a > b ? a : b;
}

int maxDepth(TreeNode *root){
	if (root == NULL)
	{
		/* code */
		return 0;
	}
	if (root ->left == NULL && root ->right == NULL)
	{
		/* code */
		return 1;
	}
	else if (root ->left == NULL && root ->right != NULL)
	{
		/* code */
		return maxDepth(root ->right)+1;
	}
	else if (root ->left != NULL && root ->right == NULL)
	{
		/* code */
		return maxDepth(root ->left)+1;
	}
	else {
		return get_max(maxDepth(root ->left), maxDepth(root ->right))+1;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(1);
	TreeNode left1(2);
	TreeNode right1(3);
	TreeNode left2(4);
	root.left = &left1;
	root.right = &right1;
	left1.left = &left2;
	cout <<maxDepth(&root) <<endl;
	return 0;
}