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
        ListNode* odd= new ListNode();
        ListNode* even= new ListNode();
        ListNode* odditr= odd;
        ListNode* evenitr= even;
        int i=1;

        while(head){
           if(i%2==0){
                evenitr->next=head;
                evenitr=evenitr->next;
           }else{
            odditr->next=head;
                odditr=odditr->next;
           }
           i++;
           head=head->next;
        }
        evenitr->next=NULL;
        odditr->next=even->next;
        return odd->next;
    }
};