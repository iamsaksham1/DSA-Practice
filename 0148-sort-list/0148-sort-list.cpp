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
    ListNode* merge(ListNode* left, ListNode* right){
            ListNode temp1(0);
            ListNode* temp = &temp1;

            while(left!=nullptr && right!=nullptr){
               if(left->val < right->val){
                 temp->next = left;
                left = left->next;
               }
               else{
                temp->next = right;
                right = right->next;
               }
               temp = temp->next;
            }
            if( left!= nullptr){
                temp->next = left;
            }
            if( right!=nullptr){
                temp->next = right;
            }
            return temp1.next;
        }
        ListNode* sortList(ListNode* head){
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            // finding the middle element of the list
            ListNode* slow = head;
            ListNode* fast = head->next;

            while(fast!=nullptr && fast->next!= nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            // spliting the two halves - left and right
            ListNode* right = slow->next;
            slow->next = nullptr;

            // sorting both halves - left and right
            ListNode* left = sortList(head);
            right = sortList(right);

            // merge both halves
            return merge(left, right);
        
    }
};