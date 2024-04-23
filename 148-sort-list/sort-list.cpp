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

    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            if(fast->next->next!=nullptr){
                fast=fast->next->next;
            }
        }

        // if(fast->next!=nullptr){
        //     return slow->next;
        // }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        
       ListNode* temp1 = left;
       ListNode* temp2 = right;

       ListNode* tempHead = nullptr;

       if(temp1->val > temp2->val){
            tempHead = new ListNode(temp2->val);
            temp2 = temp2->next;
       }else{
        tempHead = new ListNode(temp1->val);
        temp1 = temp1->next;
       }

       ListNode* mergehead = tempHead;

       while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->val > temp2->val){
            ListNode* temp = new ListNode(temp2->val);
            tempHead->next = temp;
            temp2 = temp2->next;
        }else{
            ListNode* temp = new ListNode(temp1->val);
            tempHead->next = temp;
            temp1 = temp1->next;

        }

        tempHead = tempHead->next;
       }

        while(temp1!=NULL){
            ListNode* newNode = new ListNode(temp1->val);
            tempHead->next = newNode;
            temp1 = temp1->next;
            tempHead = tempHead->next;
        }

        while(temp2!=NULL){
            ListNode* newNode = new ListNode(temp2->val);
            tempHead->next = newNode;
            temp2 = temp2->next;
            tempHead = tempHead->next;
        }

        return mergehead;


    }

    ListNode* mergeSort(ListNode* head){

        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* middle = getMiddle(head);

        cout<<"middle:"<<middle->val<<endl;
        ListNode* leftNode = head;
        ListNode* rightNode = middle->next;
        middle->next = nullptr;
        // cout<<"right:"<<rightNode->val<<endl;

         leftNode = mergeSort(leftNode);
        rightNode = mergeSort(rightNode);

        return merge(leftNode, rightNode);


    }
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next == nullptr){
            return head;
        }

        return mergeSort(head);

        
    }
};