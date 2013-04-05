#include <iostream>
using namespace std;



struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};


void connect (TreeLinkNode *root){
	if (root == NULL)
	{
		/* code */
		return;
	}
	if (root ->left != NULL && root ->right != NULL)
	{
		/* code */
		root ->left ->next = root ->right;
	}
	else if (root ->left != NULL && root ->right == NULL)
	{
		/* code */
		if (root ->next)
		{
			/* code */
			TreeLinkNode *next_temp = root ->next
			root ->left ->next = root ->next ->left;
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}