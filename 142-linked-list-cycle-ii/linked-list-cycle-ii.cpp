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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;

            if(fast->next->next){
                fast = fast->next->next;
            }

            if(slow == fast) {
                slow = head;

                while(slow!=fast){
                    fast = fast->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};