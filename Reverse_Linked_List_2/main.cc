#include <iostream>
using namespace std;




// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (m == n)
	{
		/* code */
		return head;
	}
	int count = 1;
	ListNode *prev = NULL;
	ListNode *current = head;
	ListNode *next = NULL;
	ListNode *sub_prev = NULL;
	ListNode *sub_next = NULL;
	ListNode *sub_head = NULL;
	ListNode *sub_tail = NULL;
	while (count <= n){
		next = current ->next;
		if (count == m)
		{
			/* code */
			sub_prev = prev;
			sub_head = current;
		}
		else if (count == n)
		{
			/* code */
			sub_next = next;
			sub_tail = current;
		}
		if (count <= n && count >= m)
		{
			/* code */
			current ->next = prev;
		}
		prev = current;
		current = next;
		count ++;
	}
	sub_head ->next = sub_next;
	if (sub_prev != NULL)
	{
		/* code */
		sub_prev ->next = sub_tail;
	}
	return m == 1 ? sub_tail : head;
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
	ListNode *res = reverseBetween(&a, 2, 4);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}