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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0 ;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while( l1 != nullptr || l2 != nullptr){
            int val1;
            int val2;

            // get value from l1
            // if l1 is finished, use 0
            if (l1 == nullptr) {
                val1 = 0;
            }
            else {
                val1 = l1->val;
            }

            // get value from l2
            // if l2 is finished, use 0
            if (l2 == nullptr) {
                val2 = 0;
            }
            else {
                val2 = l2->val;
            }

            int total = val1 + val2 + carry;
            int digit = total % 10;
            carry = total/10 ;

            // create a new node
            ListNode* newNode = new ListNode (digit) ;
            tail->next = newNode ;
            tail = tail->next ;

            if (l1 != nullptr) {
                l1 = l1->next;
                }
                if (l2 != nullptr) {
                l2 = l2->next;
                }
        }
        // if we have an additional carry remaining
        if (carry != 0){
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;
        }
        return dummy->next;
    }
};