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

void pop_front(vector<int> &v){
	for (int i = 0; i < v.size()-1; ++i)
	{
		/* code */
		v[i] = v[i+1];
	}
	v.pop_back();
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start, int end) {
	if (start == end)
	{
		/* code */
		return NULL;
	}
	TreeNode *root = new TreeNode(preorder[0]);
	pop_front(preorder);
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
	root ->left = build(preorder, inorder, start, mid_index);
	root ->right = build(preorder, inorder, mid_index+1, end);
	return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	return build(preorder, inorder, 0, inorder.size());
}


int main(int argc, char const *argv[])
{
	/* code */
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(3);
	vector<int> inorder;
	inorder.push_back(1);
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(4);
	TreeNode *root = buildTree(preorder, inorder);
	cout <<root ->val <<endl;
	cout <<root ->right ->val <<endl;
	cout <<root ->right ->right ->val <<endl;
	cout <<root ->right ->right ->left ->val <<endl;
	return 0;
}