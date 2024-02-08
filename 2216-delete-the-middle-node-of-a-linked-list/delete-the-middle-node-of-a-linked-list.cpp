/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return NULL;
        }


       

        ListNode* slow = head;
        ListNode* fast = head->next;

        while( fast->next!=NULL && fast->next->next!=NULL){

            // if(slow->next!=NULL){
                slow = slow->next;
                if(fast->next->next!=NULL){
                    fast = fast->next->next;
                }
            // }

           
        }

        cout<<"slow: "<<slow->val;

        if(slow->next!=NULL){
            slow->next = slow->next->next;
        }

    
        return head;
        
    }
};