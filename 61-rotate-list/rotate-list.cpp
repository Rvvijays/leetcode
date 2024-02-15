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

    int length(ListNode* head){
        ListNode* temp = head;

        int count = 0;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }

        return count;

    }

    ListNode* getKthNode(ListNode* head, int k){
        if(head == NULL){
            return head;
        }

      

        int fromStart = k - 1;

        // cout<<"fromstart:"<<fromStart;

       

        ListNode* temp = head;
        

        while(fromStart > 0){
            temp = temp->next;
            fromStart--;
        }



        // ListNode* slow = temp;
        // ListNode* fast = slow;

        // while(fast->next!=NULL && fast->next->next!=NULL){
        //     if(fast->next->next!=NULL){
        //         slow = slow->next;
        //         fast = fast->next->next;
        //     }
        // }

       

        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        int len = length(head);

        k = k % len;

        if(k == 0){
            return head;
        }

        k = len - k;

        ListNode* temp = getKthNode(head,k);
        // cout<<"kthNode:"<<temp->val;

        ListNode* next = temp->next;
        temp->next = NULL;

        ListNode* oldHead= head;
        head = next;

        while(next->next!=NULL){
            next = next->next;
        }

        next->next = oldHead;

        return head;





    }
};