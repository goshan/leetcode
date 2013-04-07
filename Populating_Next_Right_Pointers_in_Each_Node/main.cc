#include <iostream>
#include <queue>
using namespace std;



struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode *find_next(TreeLinkNode *current){
	TreeLinkNode *next_temp = current ->next;
	while (next_temp != NULL){
		if (next_temp ->left != NULL || next_temp ->right != NULL)
		{
			/* code */
			return next_temp;
		}
		next_temp = next_temp ->next;
	}
	return NULL;
}

void connect_node (TreeLinkNode *root){
	if (root == NULL)
	{
		/* code */
		return;
	}
	TreeLinkNode *next_temp = find_next(root);
	if (next_temp == NULL)
	{
		/* code */
		next_temp = NULL;
	}
	else if (next_temp ->left != NULL)
	{
		/* code */
		next_temp = next_temp ->left;
	}
	else if (next_temp ->right != NULL)
	{
		/* code */
		next_temp = next_temp ->right;
	}
	else {
		next_temp = NULL;
	}
	
	if (root ->left != NULL && root ->right != NULL)
	{
		/* code */
		root ->left ->next = root ->right;
		root ->right ->next = next_temp;
	}
	else if (root ->left != NULL && root ->right == NULL)
	{
		/* code */
		root ->left ->next = next_temp;
	}
	else if (root ->left == NULL && root ->right != NULL)
	{
		/* code */
		root ->right ->next = next_temp;
	}
}

void connect (TreeLinkNode *root){
	if (root == NULL)
	{
		/* code */
		return;
	}
	queue<TreeLinkNode *> cache;
	cache.push(root);
	while (cache.size() != 0){
		TreeLinkNode *temp = cache.front();
		cache.pop();
		connect_node(temp);
		if (temp ->left != NULL)
		{
			/* code */
			cache.push(temp ->left);
		}
		if (temp ->right != NULL)
		{
			/* code */
			cache.push(temp ->right);
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	TreeLinkNode root(1);
	TreeLinkNode left1(2);
	TreeLinkNode right1(3);
	TreeLinkNode left2(4);
	TreeLinkNode right2(5);
	TreeLinkNode right3(7);
	root.left = &left1;
	root.right = &right1;
	left1.left = &left2;
	left1.right = &right2;
	right1.right = &right3;
	connect(&root);
	cout <<root.next <<endl;
	cout <<left1.next ->val <<endl;
	cout <<right1.next <<endl;
	cout <<left2.next ->val <<" " <<right2.next ->val <<endl;
	cout <<right3.next <<endl;
	return 0;
}