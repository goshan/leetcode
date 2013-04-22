#include <iostream>
using namespace std;







// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (head == NULL)
	{
		/* code */
		return head;
	}
	ListNode *current = head ->next;
	ListNode *prev = head;
	while (current != NULL){
		if (current ->val == prev ->val)
		{
			/* code */
			prev ->next = current ->next;
		}
		else {
			prev = current;
		}
		current = current ->next;
	}
	return head;
}

int main(int argc, char const *argv[])
{
	/* code */
	ListNode a(1);
	ListNode b(1);
	ListNode c(2);
	ListNode d(3);
	ListNode e(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *res = deleteDuplicates(&a);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}