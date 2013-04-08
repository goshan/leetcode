#include <iostream>
using namespace std;






// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *com_sortedListToBST(ListNode *head, ListNode *tail) {
	if (head == tail)
	{
		/* code */
		return new TreeNode(head ->val);
	}
	int len = 0;
	ListNode *pre = head;
	while (pre != tail){
		len ++;
		pre = pre ->next;
	}
	len = (len+1)/2;
	pre = head;
	for (int i = 0; i < len-1; ++i)
	{
		/* code */
		pre = pre ->next;
	}
	ListNode *mid = pre ->next;
	ListNode *pos = mid ->next;

	TreeNode *root = new TreeNode(mid ->val);
	if (mid == tail)
	{
		/* code */
		root ->left = com_sortedListToBST(head, pre);
		root ->right = NULL;
	}
	else {
		root ->left = com_sortedListToBST(head, pre);
		root ->right = com_sortedListToBST(pos, tail);
	}
	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (head == NULL)
	{
		/* code */
		return NULL;
	}
	ListNode *tail = head;
	while (tail ->next != NULL){
		tail = tail ->next;
	}
	return com_sortedListToBST(head, tail);
}


int main(int argc, char const *argv[])
{
	/* code */
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	TreeNode *head = sortedListToBST(&a);
	cout <<head ->val <<endl;
	return 0;
}