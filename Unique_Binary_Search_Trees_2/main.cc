#include <iostream>
#include <vector>
using namespace std;






// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

vector<TreeNode *> generate(int &current, int n) {
	vector<TreeNode *> res;
	if (n == 0) {
		res.push_back(NULL);
		return res;
	}
	int temp = current;
	for (int i = 0; i <= n-1; ++i)
	{
		/* code */
		vector<TreeNode *> left = generate(current, i);
		int root_val = current;
		current ++;
		vector<TreeNode *> right = generate(current, n-1-i);
		current = temp;
		for (int j=0; j<left.size(); j++){
			for (int k=0; k<right.size(); k++){
				TreeNode *root = new TreeNode(root_val);
				root ->left = left[j];
				root ->right = right[k];
				res.push_back(root);
			}
		}
	}
	current += n;
	return res;
}

vector<TreeNode *> generateTrees(int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int current = 1;
	return generate(current, n);
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<TreeNode *> res = generateTrees(3);
	cout <<res.size() <<endl;
	return 0;
}