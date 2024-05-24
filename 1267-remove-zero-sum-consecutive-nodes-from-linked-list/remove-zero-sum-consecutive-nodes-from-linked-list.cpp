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
    ListNode* removeZeroSumSublists(ListNode* head) {

        // ListNode* temp = head;

        // if (temp == nullptr) {
        //     return nullptr;
        // }

        // // if(temp->next == nullptr && temp->val == 0) {
        // //     return nullptr;
        // // }

        // /*
        // 1   2   3  -3   1
        //         t   n

        // sum = 0




        // */
        // ListNode* tempPrev = head;
        // while (temp != nullptr) {
        //     int prefixSum = temp->val;

        //     if (prefixSum == 0) {
        //         if (temp == head) {
        //             head = temp->next;
        //         } else {
        //             tempPrev->next = temp->next;
        //         }
        //         tempPrev = temp;
        //         temp = temp->next;
        //         continue;
        //     }

        //     // if(prefixSum == 0) {
        //     //     tempPrev->next = temp->next;
        //     // }

        //     ListNode* next = temp->next;

        //     while (next != nullptr) {
        //         prefixSum += next->val;

        //         if (prefixSum == 0) {
        //             if (temp == head) {
        //                 head = next->next;
        //             } else {
        //                 tempPrev->next = next->next;
        //             }
        //             break;
        //         }
        //         next = next->next;
        //     }

        //     tempPrev = temp;
        //     temp = temp->next;
        // }

        // return head;

        ListNode* front = new ListNode(0,head);
        ListNode* start = front;

        while(start!=nullptr) {
            int prefixSum = 0;
            ListNode* end = start->next;

            while(end!=nullptr) {
                prefixSum += end->val;

                if(prefixSum ==0 ){
                    start->next = end->next;
                }

                end = end->next;
            }

            start = start->next;
        }

        return front->next;
    }
};