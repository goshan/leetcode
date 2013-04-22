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
	ListNode *current = head;
	ListNode *sub_head = NULL;
	while (current != NULL){
		if (current ->next == NULL || current ->val != current ->next ->val) {
			if (sub_head == NULL)
			{
				/* code */
				if (current == head)
				{
					/* code */
					sub_head = current;
					current = current ->next;
				}
				else {
					head = current ->next;
					current = current ->next;
				}
			}
			else {
				if (sub_head ->next == current)
				{
					/* code */
					sub_head = current;
					current = current ->next;
				}
				else {
					sub_head ->next = current ->next;
					current = current ->next;
				}
			}
		}
		else
		{
			/* code */
			current = current ->next;
		}
	}
	return head;
}

int main(int argc, char const *argv[])
{
	/* code */
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(3);
	ListNode e(4);
	ListNode f(4);
	ListNode g(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	ListNode *res = deleteDuplicates(&a);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}