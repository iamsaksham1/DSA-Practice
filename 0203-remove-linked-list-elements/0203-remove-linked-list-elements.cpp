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
    ListNode* removeElements(ListNode* head, int val) {
        // If node to remove is at head 
        while( head!= nullptr && head->val == val){
            head = head -> next;
        }
        if(head == nullptr){
            return nullptr;
        }
        // traversing the list using a temp node
        struct ListNode* temp = head;
        while(temp->next != nullptr){
            if(temp->next->val == val){
                // skip this node
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};