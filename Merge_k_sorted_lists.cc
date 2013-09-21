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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        ListNode *head = NULL;
        ListNode *current = NULL;
        while (sum != lists.size()){
            int min = 100000;
            int min_index = -1;
            for (int i=0; i<lists.size(); i++){
                if (lists[i] != NULL && lists[i] ->val < min){
                    min = lists[i] ->val;
                    min_index = i;
                }
            }
            if (min_index != -1){
                if (head == NULL){
                    head = lists[min_index];
                    current = head;
                }
                else {
                    current -> next = lists[min_index];
                    current = lists[min_index];
                }
                lists[min_index] = lists[min_index] ->next;
                if (lists[min_index] == NULL){
                    sum ++;
                }
            }
            else {
                break;
            }
            
        }
        return head;
    }
};