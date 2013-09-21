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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL){
            return head;
        }
        else if (head ->next == NULL){
            return head;
        }
        ListNode *current = head;
        head = head ->next;
        ListNode *prev = NULL;
        while (current != NULL){
            if (current ->next != NULL){
                if (prev != NULL){
                    prev ->next = current ->next;
                }
                ListNode *next = current ->next ->next;
                current ->next ->next = current;
                current ->next = next;
                prev = current;
                current = next;
            }
            else {
                break;
            }
        }
        return head;
    }
};