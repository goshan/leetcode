#include <iostream>
using namespace std;







// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *rotateRight(ListNode *head, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (head == NULL || head ->next == NULL || k == 0)
	{
		/* code */
		return head;
	}
	ListNode *point = NULL;
	ListNode *prev = head;
	ListNode *current = head ->next;
	int cnt = 1;
	while (current != NULL){
		if (cnt == k)
		{
			/* code */
			point = head;
		}
		else {
			if (point != NULL)
			{
				/* code */
				point = point ->next;
			}
		}
		cnt ++;
		current = current ->next;
		prev = prev ->next;
	}
	if (point == NULL)
	{
		/* code */
		k = k%cnt;
		return rotateRight(head, k);
	}
	prev ->next = head;
	head = point ->next;
	point ->next = NULL;
	return head;
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
	ListNode *res = rotateRight(&a, 2);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}