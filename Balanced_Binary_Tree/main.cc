#include <iostream>
#include <math.h>
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

void get_depth(TreeNode *root){
	int left_depth = 0;
	int right_depth = 0;
	if (root ->left != NULL)
	{
		/* code */
		get_depth(root ->left);
		left_depth = root ->left ->val;
	}
	if (root ->right != NULL)
	{
		/* code */
		get_depth(root ->right);
		right_depth = root ->right ->val;
	}
	root ->val = get_max(left_depth, right_depth) + 1;
}

bool balanced(TreeNode *root){
	int left_depth = 0;
	int right_depth = 0;
	if (root == NULL)
	{
		/* code */
		return true;
	}
	if (root ->left != NULL)
	{
		/* code */
		left_depth = root ->left ->val;
	}
	if (root ->right != NULL)
	{
		/* code */
		right_depth = root ->right ->val;
	}
	if (abs(left_depth - right_depth) > 1)
	{
		/* code */
		return false;
	}
	else if (!balanced(root ->left) || !balanced(root ->right))
	{
		/* code */
		return false;
	}
	return true;
}

bool isBalanced(TreeNode *root){
	if (root == NULL)
	{
		/* code */
		return true;
	}
	get_depth(root);
	return balanced(root);
}


int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(1);
	TreeNode left1(2);
	TreeNode right1(2);
	root.left = &left1;
	root.right = &right1;
	TreeNode left2(3);
	left1.left = &left2;
	TreeNode right2(3);
	right1.right = &right2;
	TreeNode left3(4);
	TreeNode right3(4);
	left2.left = &left3;
	right2.right = &right3;
	cout <<isBalanced(&root) <<endl;
	return 0;
}