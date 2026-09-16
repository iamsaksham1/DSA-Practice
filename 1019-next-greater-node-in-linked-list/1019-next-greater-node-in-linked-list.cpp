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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int>res;
        while(head){
            ListNode* temp=head->next;
            while(temp && temp->val<=head->val){
                temp=temp->next;
            }
            if(temp){
                res.push_back(temp->val);
            }else{
                res.push_back(0);
            }
            head=head->next;
        }
        return res;
    }
};