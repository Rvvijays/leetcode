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

    ListNode* brute(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp!=NULL)
        nums.push_back(temp->val);
        temp = temp->next;
        sort(nums.begin(),nums.end());
        int count = 0;
        temp = head;
        while(temp!=NULL){
            temp->val = nums[count++];
            temp = temp->next;
        }
        return head;
    }

    ListNode* better(ListNode* head) {


        ListNode* temp = head;

        while(temp!=NULL){
            int data = temp->val;
            ListNode* temp2 = head;

            while(temp2!=NULL){
            if(temp->val < temp2->val){
                int t = temp2->val;
                temp2->val = temp->val;
                temp->val = t;
            }
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        return head;
    }

    ListNode* getMiddle(ListNode* head){
        if(head == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            if(fast->next->next!=NULL){
                fast = fast->next->next;
            }
        }

        return slow;
    }

    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        ListNode* tempHead = NULL;

        if(temp1->val > temp2->val){
            tempHead = new ListNode(temp2->val);
            temp2 = temp2->next;
            
        }else{
            tempHead = new ListNode(temp1->val);
            temp1 = temp1->next;
        }

        ListNode* mergedList = tempHead;
        // tempHead = tempHead->next;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val > temp2->val){
                ListNode* newNode = new ListNode(temp2->val);
                tempHead->next = newNode;
                temp2 = temp2->next;
            }else{
                ListNode* newNode = new ListNode(temp1->val);
                tempHead->next = newNode;
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

        return mergedList;

    }
  


    
    ListNode* mergesort(ListNode* head){
        if(head == NULL || head->next==NULL){
            return head;
        }

        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* lefthead = mergesort(head);
        ListNode* righthead = mergesort(right);

        return merge(lefthead,righthead);
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* temp = head;
        temp = mergesort(temp);

        return temp;
    }
};