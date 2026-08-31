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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int position = 2;
        int firstCritical = -1;
        int previousCritical = -1;

        int minDistance = INT_MAX;
        int maxDistance = 0;

        while (next != NULL) {
            // Checking whether curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {
                // First critical point dhudho
                if (firstCritical == -1) {
                    firstCritical = position;
                    previousCritical = position;
                }
                else {
                    // Distance from previous critical point nikalo
                    int distance = position - previousCritical;
                    minDistance = min(minDistance, distance);
                    // Distance from first critical point
                    maxDistance = max(maxDistance,
                                      position - firstCritical);
                    previousCritical = position;
                }
            }
            // Move the pointers forward
            prev = curr;
            curr = next;
            next = curr->next;
            position++;
        }
        // Fewer than two critical points wali condition
        if (firstCritical == previousCritical)
            return ans;

        ans[0] = minDistance;
        ans[1] = maxDistance;

        return ans;
    }
};