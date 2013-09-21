/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        while (curr1 ->next != NULL && curr2 ->next != NULL){
            curr1 ->val += curr2 ->val;
            curr1 = curr1 ->next;
            curr2 = curr2 ->next;
        }
        if (curr1 ->next == NULL){
            curr1 ->val += curr2 ->val;
            curr1 ->next = curr2 ->next;
        }
        else if (curr2 ->next == NULL){
            curr1 ->val += curr2 ->val;
        }
        curr1 = l1;
        while (curr1 ->next != NULL){
            if (curr1 ->val >9){
                curr1 ->next ->val += curr1 ->val/10;
                curr1 ->val -= curr1 ->val/10*10;
            }
            curr1 = curr1 ->next;
        }
        if (curr1 ->val > 9){
            ListNode *n = new ListNode(curr1 ->val/10);
            curr1 ->val -= curr1 ->val/10*10;
            curr1 ->next = n;
        }
        return l1;
    }
};