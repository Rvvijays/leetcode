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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* finalList = NULL;
        ListNode* temp = NULL;

        int carry = 0;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val + temp2->val + carry;

            carry = sum/10;
            int digit = sum%10;
            temp1 = temp1->next;
            temp2= temp2->next;

            if(temp==NULL){
                temp = new ListNode(digit);
                finalList = temp;
                continue;
            }

            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = temp->next;
        }

        while(temp1!=NULL){
            int sum = temp1->val + carry;
            carry = sum/10;
            int digit = sum%10;
            temp1 = temp1->next;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = temp->next;
        }

        while(temp2!=NULL){
            int sum = temp2->val + carry;
            carry = sum/10;
            int digit = sum%10;
            temp2 = temp2->next;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = temp->next;
        }

        if(carry !=0){
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
            // temp = temp->next;
        }

        return finalList;
    }
};