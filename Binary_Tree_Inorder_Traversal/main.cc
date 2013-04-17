#include <iostream>
#include <stack>
#include <vector>
using namespace std;





// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> res;
	if (root == NULL)
	{
		/* code */
		return res;
	}
	stack<TreeNode *> cache;
	cache.push(root);
	while (cache.size() != 0){
		TreeNode *temp = cache.top();
		cache.pop();
		if (temp ->left == NULL && temp ->right == NULL)
		{
			/* code */
			res.push_back(temp ->val);
			continue;
		}
		if (temp ->right != NULL)
		{
			/* code */
			cache.push(temp ->right);
			temp ->right = NULL;
		}
		cache.push(temp);
		if (temp ->left != NULL)
		{
			/* code */
			cache.push(temp ->left);
			temp ->left = NULL;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(1);
	TreeNode right(2);
	TreeNode left(3);
	root.right = &right;
	right.left = &left;
	vector<int> res = inorderTraversal(&root);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		cout <<res[i] <<endl;
	}
	return 0;
}