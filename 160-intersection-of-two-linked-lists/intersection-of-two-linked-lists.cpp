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
    ListNode* brute(ListNode* headA, ListNode* headB) {
        map<ListNode*,bool> hash;   

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1!=NULL){
            if(hash[temp1]){
                return temp1;
            }else{
                hash[temp1] = true;
            }
            temp1= temp1->next;
        } 

        while(temp2!=NULL){
            if(hash[temp2]){
                return temp2;
            }else{
                hash[temp2] = true;
            }
            temp2 =temp2->next;
        }

        return NULL;
    }

    int length(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = length(headA);
        int lengthB = length(headB);

        int diff = abs(lengthA - lengthB);

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(lengthA > lengthB){
            while(diff>0){
                diff--;
                temp1 = temp1->next;
            }
        }else{
            while(diff>0){
                diff--;
                temp2 = temp2->next;
            }
        }

        while(temp1!=NULL && temp2!=NULL){
            if(temp1 == temp2){
                return temp1;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;

        
    }
};