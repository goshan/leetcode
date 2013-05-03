#include <iostream>
using namespace std;





// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (l1 == NULL)
	{
		/* code */
		return l2;
	}
	else if (l2 == NULL){
		return l1;
	}
	ListNode *res = l1 ->val < l2 ->val ? l1 : l2;
	ListNode *res_pointer = res;
	ListNode *l1_pointer = l1 ->val < l2 ->val ? l1 ->next : l1;
	ListNode *l2_pointer = l1 ->val < l2 ->val ? l2 : l2 ->next;
	while (l1_pointer != NULL && l2_pointer != NULL){
		if (l1_pointer ->val < l2_pointer ->val)
		{
			/* code */
			res_pointer ->next = l1_pointer;
			res_pointer = res_pointer ->next;
			l1_pointer = l1_pointer ->next;
		}
		else {
			res_pointer ->next = l2_pointer;
			res_pointer = res_pointer ->next;
			l2_pointer = l2_pointer ->next;
		}
	}
	res_pointer ->next = l1_pointer==NULL ? l2_pointer : l1_pointer;
	return res;
}



int main(int argc, char const *argv[])
{
	/* code */
	ListNode a1(1);
	ListNode a2(4);
	ListNode a3(6);
	ListNode b1(2);
	ListNode b2(5);
	a1.next = &a2;
	a2.next = &a3;
	b1.next = &b2;
	ListNode *res = mergeTwoLists(&a1, &b1);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}