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
    ListNode* deleteDuplicates(ListNode* head) {

        // create a new dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = head;
        ListNode* prev = dummy;

        while(temp!=nullptr){
            if(temp->next != nullptr && temp->val == temp->next->val){
                // dublicate found
                //skip the entire range
                int value = temp->val;
                while(temp!=nullptr && temp->val == value){
                    temp = temp->next;
                }
                prev->next = temp;
            }

            // if dublicate not found , move the pointers forward
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};