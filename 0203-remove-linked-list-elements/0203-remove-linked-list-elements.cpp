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

        // Remove matching nodes from the beginning
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        // If the list became empty
        if (head == nullptr) {
            return nullptr;
        }

        // Traverse the remaining list
        ListNode* temp = head;

        while (temp->next != nullptr) {

            if (temp->next->val == val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};