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
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = even;

        ListNode* temp = even->next;
        int count = 1;

      while(temp!=nullptr){
        if(count%2==0){
            even->next = temp;
            even = even->next;
        }else{
            odd->next = temp;
            odd = odd->next;
        }

        temp = temp->next;
        count++;
      }

      if(even->next!=nullptr){
        even->next = nullptr;
      }

      odd->next = evenHead;

      return head;


        
    }
};