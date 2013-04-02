#include <iostream>
#include <vector>
using namespace std;









struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > comPathSum(TreeNode *root, int sum, int parent_val) {
	vector<vector<int> > res;
	if (root == NULL)
	{
		/* code */
		return res;
	}
	if (root ->left == NULL && root ->right == NULL)
	{
		/* code */
		if (root ->val+parent_val == sum)
		{
			/* code */
			res.push_back(vector<int>(1, root ->val));
		}
		return res;
	}
	if (root ->left != NULL)
	{
		/* code */
		vector<vector<int> >temp = comPathSum(root ->left, sum, parent_val+root ->val);
		if (temp.size() != 0)
		{
			/* code */
			for (int i = 0; i < temp.size(); ++i)
			{
				/* code */
				temp[i].push_back(root ->val);
				res.push_back(temp[i]);
			}
		}
	}
	if (root ->right != NULL)
	{
		/* code */
		vector<vector<int> >temp = comPathSum(root ->right, sum, parent_val+root ->val);
		if (temp.size() != 0)
		{
			/* code */
			for (int i = 0; i < temp.size(); ++i)
			{
				/* code */
				temp[i].push_back(root ->val);
				res.push_back(temp[i]);
			}
		}
	}
	return res;
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > temp = comPathSum(root, sum, 0);
	vector<vector<int> > res;
	for (int i = 0; i < temp.size(); ++i)
	{
		/* code */
		vector<int> elem;
		for (int j=temp[i].size()-1; j>=0; j--){
			elem.push_back(temp[i][j]);
		}
		res.push_back(elem);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(-2);
	TreeNode right(-3);
	root.right = &right;
	cout <<pathSum(&root, -5).size() <<endl;
	return 0;
}