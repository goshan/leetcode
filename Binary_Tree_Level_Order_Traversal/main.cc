#include <iostream>
#include <vector>
#include <queue>
using namespace std;







// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > res;
	if (root == NULL)
	{
		/* code */
		return res;
	}
	queue<TreeNode *> cache;
	cache.push(root);
	int next_num = 0;
	int current_num = 1;
	vector<int> elem;
	while (cache.size() != 0){
		TreeNode *temp = cache.front();
		cache.pop();
		current_num --;
		elem.push_back(temp ->val);
		if (temp ->left != NULL)
		{
			/* code */
			cache.push(temp ->left);
			next_num ++;
		}
		if (temp ->right != NULL)
		{
			/* code */
			cache.push(temp ->right);
			next_num ++;
		}

		if (current_num == 0)
		{
			/* code */
			res.push_back(elem);
			elem.clear();
			current_num = next_num;
			next_num = 0;
		}
	}
	
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(3);
	TreeNode left(9);
	TreeNode right(20);
	TreeNode left1(15);
	TreeNode right1(7);
	root.left = &left;
	root.right = &right;
	right.left = &left1;
	right.right = &right1;
	vector<vector<int> > res = levelOrder(&root);
	for (int i = 0; i < res.size(); ++i)
	{
		/* code */
		for (int j=0; j<res[i].size(); j++){
			cout <<res[i][j] <<" ";
		}
		cout <<endl;
	}

	return 0;
}