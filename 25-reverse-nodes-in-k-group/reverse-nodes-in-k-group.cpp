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

    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head;

        ListNode* prev = NULL;

        while(curr->next!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        curr->next = prev;

        return curr;
    }

    ListNode* getKthNode(ListNode* head,int k){
        if(head == NULL){
            return head;
        }

        ListNode* temp = head;
        int count = 1;

        while(temp!=NULL){
            temp = temp->next;
            count++;
            if(count == k){
                break;
            }
        }

       if(count == k){
           return temp;
       }

        return NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL){

            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode == NULL){
                if(prev!=NULL){
                    prev->next = temp;
                }
                
                return head;
            }

            ListNode* next = kthNode->next;
            kthNode->next = NULL;

            ListNode* reverseHead = reverse(temp);

            if(temp == head){
                head = reverseHead;
            }

            if(prev!=NULL){
                prev->next = reverseHead;
            }

            prev = temp;

            temp = next;
        }

        return head;

        

        
    }
};