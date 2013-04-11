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

bool vectorIsSymmetric(vector<int> &v){
	for (int i = 0; i < v.size()/2; ++i)
	{
		/* code */
		if (v[i] != v[v.size()-1-i])
		{
			/* code */
			return false;
		}
	}
	return true;
}

bool isSymmetric(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	queue<TreeNode *> cache;
	cache.push(root);
	int next_num = 0;
	int current_num = 1;
	vector<int> elem;
	while (cache.size() != 0){
		TreeNode *temp = cache.front();
		cache.pop();
		if (temp == NULL)
		{
			/* code */
			elem.push_back(-100000);
		}
		else {
			elem.push_back(temp ->val);
			cache.push(temp ->left);
			next_num ++;
			cache.push(temp ->right);
			next_num ++;
		}
		current_num --;

		if (current_num == 0)
		{
			/* code */
			current_num = next_num;
			next_num = 0;
			if (vectorIsSymmetric(elem)){
				elem.clear();
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode root(1);
	TreeNode left(2);
	TreeNode right(2);
	TreeNode left1(3);
	TreeNode right1(4);
	TreeNode left2(4);
	TreeNode right2(3);
	root.left = &left;
	root.right = &right;
	left.left = &left1;
	left.right = &right1;
	right.left = &left2;
	right.right = &right2;
	cout <<isSymmetric(&root) <<endl;
	return 0;
}