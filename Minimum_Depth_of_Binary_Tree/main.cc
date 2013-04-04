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

int get_min(int a, int b){
	return a < b ? a : b;
}

int minDepth(TreeNode *root){
	if (root == NULL)
	{
		/* code */
		return 0;
	}
	if (root ->left == NULL || root ->right == NULL)
	{
		/* code */
		return 1;
	}
	return get_min(minDepth(root ->left), minDepth(root ->right))+1;
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
	cout <<minDepth(&root) <<endl;
	return 0;
}