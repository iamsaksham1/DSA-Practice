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
    int numComponents(ListNode* head, vector<int>& nums) {

        unordered_set<int> s;
        // puting the value of nums into set
        for (int x : nums) {
            s.insert(x);
        }

        int count = 0;
        ListNode* temp = head;
        while (temp) {
            // for current node belongs to nums
            if (s.count(temp->val)) {
                // if next node is not in nums,
                // current component or count ends here
                if (temp->next == nullptr ||
                    !s.count(temp->next->val)) {
                    count++;
                }
            }
            temp = temp->next;
        }
        return count;
    }
};