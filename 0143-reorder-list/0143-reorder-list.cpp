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

    ListNode* reverseList(ListNode* head){
        ListNode* rev=NULL;

        while(head){
            ListNode* temp=head;
            head=head->next;
            temp->next=rev;
            rev=temp;
        }
        return rev;

    }
    void reorderList(ListNode* head) {

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next&& fast->next->next ){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        
        ListNode* l1=head;
        ListNode* l2=reverseList(mid);
        ListNode* res=new ListNode();
        ListNode* temp= res;
        while(l1&&l2){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
            temp->next=l2;
            l2=l2->next;
            temp=temp->next;
        }
        if(l2){
            temp->next=l2;
        }
         if(l1){
            temp->next=l1;
        }

        head=res->next;
        
    }
};