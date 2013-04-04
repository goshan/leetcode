#include <iostream>
#include <queue>
using namespace std;



struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};


void connect (TreeLinkNode *root){
	TreeLinkNode flag(-1000);
	queue<TreeLinkNode *> cache;
	cache.push(root);
	TreeLinkNode *last = NULL;
	int sum = 0;
	int num = 0;
	while (cache.size() != 0){
		TreeLinkNode *temp = cache.front();
		cache.pop();
		if (last != NULL)
		{
			/* code */
			last ->next = temp;
		}
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}