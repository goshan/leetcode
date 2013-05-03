#include <iostream>
using namespace std;






struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *mergeList(ListNode *a, ListNode *b){
	if (a == NULL)
	{
		/* code */
		return b;
	}
	else if (b == NULL){
		return a;
	}
	ListNode *res = a ->val < b ->val ? a : b;
	ListNode *res_pointer = res;
	ListNode *a_pointer = a ->val < b ->val ? a ->next : a;
	ListNode *b_pointer = a ->val < b ->val ? b : b ->next;
	while (a_pointer != NULL && b_pointer != NULL){
		if (a_pointer ->val < b_pointer ->val)
		{
			/* code */
			res_pointer ->next = a_pointer;
			res_pointer = res_pointer ->next;
			a_pointer = a_pointer ->next;
		}
		else {
			res_pointer ->next = b_pointer;
			res_pointer = res_pointer ->next;
			b_pointer = b_pointer ->next;
		}
	}
	res_pointer ->next = a_pointer==NULL ? b_pointer : a_pointer;
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
	ListNode *res = mergeList(&a1, &b1);
	while (res != NULL){
		cout <<res ->val <<endl;
		res = res ->next;
	}
	return 0;
}