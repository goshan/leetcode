#include <iostream>
#include <vector>
using namespace std;





// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &postorder) {
	if (start == end)
	{
		/* code */
		return NULL;
	}
	TreeNode *root = new TreeNode(postorder.back());
	postorder.pop_back();
	int mid_index = -1;
	for (int i = start; i < end; ++i)
	{
		/* code */
		if (inorder[i] == root ->val)
		{
			/* code */
			mid_index = i;
			break;
		}
	}
	root ->right = build(inorder, mid_index+1, end, postorder);
	root ->left = build(inorder, start, mid_index, postorder);
	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	return build(inorder, 0, inorder.size(), postorder);
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	vector<int> postorder;
	postorder.push_back(3);
	postorder.push_back(4);
	postorder.push_back(2);
	postorder.push_back(1);
	TreeNode *root = buildTree(inorder, postorder);
	cout <<root ->val <<endl;
	cout <<root ->right ->val <<endl;
	cout <<root ->right ->right ->val <<endl;
	cout <<root ->right ->right ->left ->val <<endl;
	return 0;
}