#include <iostream>
using namespace std;







// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *less = NULL;
	ListNode *new_head = NULL;
	ListNode *more = NULL;
	ListNode *mid_head = NULL;
	ListNode *current = head;
	while (current != NULL){
		if (current ->val < x)
		{
			/* code */
			if (less != NULL)
			{
				/* code */
				less ->next = current;
				less = less ->next;
			}
			else {
				new_head = current;
				less = current;
			}
			current = current ->next;
			less ->next = NULL;
		}
		else {
			/* code */
			if (more != NULL)
			{
				/* code */
				more ->next = current;
				more = more ->next;
			}
			else {
				mid_head = current;
				more = current;
			}
			current = current ->next;
			more ->next = NULL;
		}
	}
	if (less == NULL)
	{
		/* code */
		new_head = mid_head;
	}
	else {
		less ->next = mid_head;
	}
	return new_head;
}

int main(int argc, char const *argv[])
{
	/* code */
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	ListNode *res = partition(&a, 3);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}