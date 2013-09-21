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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head ->next == NULL){
            return NULL;
        }
        ListNode *current = head;
        for (int i=0; i<n; i++){
            current = current ->next;
        }
        ListNode *prev = head;
        if (current == NULL){
            head = prev ->next;
            return head;
        }
        while (current ->next != NULL){
            current = current ->next;
            prev = prev ->next;
        }
        prev ->next = prev ->next ->next;
        return head;
    }
};