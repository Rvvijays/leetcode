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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
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
};