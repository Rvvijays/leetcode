#include<bits/stdc++.h>
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
    bool brute(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while(temp!=NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp!=NULL){
            int top = st.top();
            st.pop();
            cout<<temp->val<<" "<<top;
            if(temp->val!=top){
                return false;
            }
            temp = temp->next;
        }

        return true;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            if(fast->next->next!=NULL){
                fast = fast->next->next;
            }
        }

        if(fast->next!=NULL){
            return slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool compare(ListNode* head1, ListNode* head2){
        while(head2!=NULL){
            // cout<<"head1:"<<head1->val<< " | head2:"<<head2->val;
            if(head1->val!=head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }


        return true;
    }

    bool optimal(ListNode* head) {
        // find middle
        ListNode* temp = head;
        ListNode* mid = middle(temp);
        // cout<<"middle"<<mid->val;

        ListNode* head2 = reverse(mid);

        // cout<<"middle: "<<mid->val;
        ListNode* head1 = head;

        // while(head1!=NULL){
        //     cout<<head1->val<<" ";
        //     head1 = head1->next;
        // }

        // cout<<"ttt";

        //   while(head2!=NULL){
        //     cout<<head2->val<<" ";
        //     head2 = head2->next;
        // }

        return compare(head1,head2);

        // return false;
    }
    bool isPalindrome(ListNode* head) {
        // return brute(head);
        return optimal(head);
    }
};