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
    ListNode* middleNode(ListNode* head) {

        if(head==nullptr){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;

            if(fast->next->next!=nullptr){
                fast = fast->next->next;
            }
        }

        if(fast->next){
            return slow->next;

            
        }

        return slow;

        
        
    }
};