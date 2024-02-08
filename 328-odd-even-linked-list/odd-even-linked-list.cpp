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

    // brute method
    // two iterations and put again.

     ListNode* brute(ListNode* head) {
        ListNode* temp = head;
       vector<int> odd;
       vector<int> even;


        int count = 1;
        while(temp!=NULL){
            if(count%2==1){
                odd.push_back(temp->val);

            }else{
                even.push_back(temp->val);
            }
            count++;
            temp = temp->next;
        }

        temp = head;
        for(int i=0; i<odd.size(); i++){
            temp->val = odd[i];
            temp = temp->next;
        }

        for(int i=0; i<even.size(); i++){
                    temp->val = even[i];
                    temp = temp->next;
                }

        return head;



     }
    ListNode* oddEvenList(ListNode* head) {

        // return brute(head);

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* temp = even;


        // 1->2->3->4->5

        // 1->2->3->4->5->6
        while(even !=NULL && even->next!=NULL){

            odd->next = odd->next->next;
            odd = odd->next;

            even->next = even->next->next;
            even = even->next;

          


        }

        if(even!=NULL && even->next!=NULL){
            even->next = NULL;
        }

        odd->next = temp;

        return head;

       
      
    }
};