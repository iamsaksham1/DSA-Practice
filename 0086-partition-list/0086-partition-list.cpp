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
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummySmall = new ListNode(0);
        ListNode* dummyLarge = new ListNode(0);

        ListNode* small = dummySmall;
        ListNode* large = dummyLarge;

        ListNode* temp = head;

        //traversing the original list
        while(temp!=nullptr){

            if( temp->val < x){
                small->next = temp;
                small = small->next;
            }
            else{
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }
        // connect the small and large lists
        small->next = dummyLarge->next;

        // terminating the large list to end 
        large->next = nullptr;

        return dummySmall->next;
    }
};