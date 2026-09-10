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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* before = dummy;
        for (int i = 1; i < left; i++) {
            before = before->next;
        }
        // first node of the section to reverse = start
        ListNode* start = before->next;

        // reverse from left to right
        // First node of the section to reverse
        ListNode* prev = nullptr;
        ListNode* curr = start;

        for(int i=left; i<=right; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // join the reverse and non reversed nodes
        before->next = prev;
        start->next = curr;

        return dummy->next;
    }
};