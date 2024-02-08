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



 ListNode* brute(ListNode* head, int n) {
if(head==NULL || head->next==NULL){
            return NULL;
        }


        ListNode* temp = head;

        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }

        int fromStart = (count - n) + 1;

        

        temp = head;

        // cout<<"fromStart:"<<fromStart;

        if(fromStart == 1) {
            temp = temp->next;
           
           return temp;

        }

        while(fromStart>2){
            fromStart--;

            temp = temp->next;
        }

        if(temp!=NULL && temp->next!=NULL){
            // cout<<"ye chalaa";
            temp->next = temp->next->next;

        }

        return head;
 }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL || head->next==NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(n>0){
            fast = fast->next;

        
            n--;
        }


        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
            cout<<"slow:"<<slow->val;



        if(fast == NULL){
            slow = slow->next;
            return slow;
        }

        slow->next = slow->next->next;

        return head;


        
    }
};