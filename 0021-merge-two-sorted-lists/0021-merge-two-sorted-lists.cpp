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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        // create a new node [ insert in middle case ]
        ListNode temp(0);
        ListNode* end = &temp;

     while(head1 != nullptr && head2 != nullptr){
        if(head1->val <= head2->val){
            end->next = head1;
            head1 = head1->next;
        }
        else{
            end->next = head2;
            head2 = head2 -> next;
        }

        end = end ->next;
     }
        // checking for the end/ tails
        if(head1 == nullptr){
            end->next = head2;
        }
        else{
            end->next = head1;
        }
     return temp.next;
    }
};