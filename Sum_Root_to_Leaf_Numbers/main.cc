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



vector<vector<int> > getNumber(TreeNode *root){
	vector<vector<int> > left_nums;
	vector<vector<int> > right_nums;
	if (root ->left == NULL && root ->right == NULL)
	{
		/* code */
		return vector<vector<int> >(1, vector<int> (1, root ->val));
	}
	else if (root ->left == NULL){
		right_nums = getNumber(root ->right);
	}
	else if (root ->right == NULL){
		left_nums = getNumber(root ->left);
	}
	else {
		left_nums = getNumber(root ->left);
		right_nums = getNumber(root ->right);
	}
	vector<vector<int> > res;
	for (int i = 0; i < left_nums.size(); ++i)
	{
		/* code */
		left_nums[i].push_back(root ->val);
		res.push_back(left_nums[i]);
	}
	for (int i = 0; i < right_nums.size(); ++i)
	{
		/* code */
		right_nums[i].push_back(root ->val);
		res.push_back(right_nums[i]);
	}
	return res;
}

int sumNumbers(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL)
	{
		/* code */
		return 0;
	}
	vector<vector<int> > nums = getNumber(root);
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		/* code */
		int num = 0;
		for (int j=0; j<nums[i].size(); j++){
			num += nums[i][j]*pow(10, j);
		}
		sum += num;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(0);
	TreeNode left(1);
	TreeNode right(3);
	root.left = &left;
	//root.right = &right;
	cout <<sumNumbers(&root) <<endl;
	return 0;
}