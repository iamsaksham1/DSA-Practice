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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int i=0;
        ListNode* temp=list1;
        while(temp && i+1!=a){
            i++;
            temp=temp->next;
        }
        ListNode* temp1=temp->next;
        i++;
        while(temp1 && i!=b+1){
            i++;
            temp1=temp1->next;
        }
        temp->next=list2;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=temp1;
        return list1;
    }
};