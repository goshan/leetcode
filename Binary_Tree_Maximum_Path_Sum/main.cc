#include <iostream>
#include <vector>
#include <math.h>
using namespace std;




struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int best_res;

void com_max(const int &a){
	if (a > best_res)
	{
		/* code */
		best_res = a;
	}
}

int getMaxSum(TreeNode *root){
	if (root ->left == NULL && root ->right == NULL)
	{
		/* code */
		com_max(root ->val);
		return root ->val;
	}
	else if (root ->left == NULL){
		int num = getMaxSum(root ->right);
		com_max(root ->val);
		com_max(num);
		com_max(root ->val + num);
		return num>0 ? root ->val+num : root ->val;
	}
	else if (root ->right == NULL){
		int num = getMaxSum(root ->left);
		com_max(root ->val);
		com_max(num);
		com_max(root ->val + num);
		return num>0 ? root ->val+num : root ->val;
	}
	else {
		int left_nums = getMaxSum(root ->left);
		int right_nums = getMaxSum(root ->right);
		int num;
		if (left_nums > right_nums)
		{
			/* code */
			num = left_nums;
		}
		else {
			num = right_nums;
		}
		com_max(root ->val);
		com_max(left_nums);
		com_max(right_nums);
		com_max(root ->val + left_nums);
		com_max(root ->val + right_nums);
		com_max(root ->val + left_nums + right_nums);
		return num>0 ? root ->val+num : root ->val;
	}
}

int maxPathSum(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	best_res = -10000000;
	if (root == NULL)
	{
		/* code */
		return 0;
	}
	getMaxSum(root);
	return best_res;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(0);
	TreeNode left(1);
	TreeNode right(2);
	TreeNode left1(0);
	TreeNode right1(1);
	TreeNode left2(-1);
	TreeNode right2(0);
	left.left = &left1;
	left.right = &right1;
	right.left = &left2;
	right.right = &right2;
	root.left = &left;
	root.right = &right;
	cout <<maxPathSum(&root) <<endl;
	return 0;
}