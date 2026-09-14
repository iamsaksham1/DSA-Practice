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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        // Count nodes
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        int size = n / k;
        int extra = n % k;
        vector<ListNode*> res;

        temp = head;

        for (int i = 0; i < k; i++) {
            // First extra parts get one extra node
            int partSize = size;

            if (extra > 0) {
                partSize++;
                extra--;
            }
            // This part starts here
            ListNode* partHead = temp;
            // Move to the end of this part
            ListNode* prev = nullptr;
            for (int j = 0; j < partSize; j++) {
                prev = temp;
                if (temp)
                    temp = temp->next;
            }
            // Cut this part from the remaining list
            if (prev)
                prev->next = nullptr;

            res.push_back(partHead);
        }
        return res;
    }
};