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
    ListNode* rotateRight(ListNode* head, int k) {

        //----O(n*k) solution----

//         if(head == nullptr || head->next == nullptr || k==0)
//         return head;

//         // count the number of nodes
//         ListNode* temp = head;
//         int n =0;
//         while(temp != nullptr){
//             n++;
//             temp = temp->next;
//         }

//         // reduce the k
//         k=k%n;

//         // rotating loop
//         int count =0;
//         while(count<k){
//             ListNode* temp = head;
//             ListNode* prev = nullptr;

//             while(temp->next!=nullptr){
//                 prev = temp;
//                 temp = temp->next;
//             }

//             prev->next = nullptr;
//             temp->next = head;
//             head = temp;
//             count++;
//         }
//         return head;
//     }
// };


//----O(n) solution----
if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length
        int n = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }

        // Reduce k
        k = k % n;

        if(k == 0)
            return head;

        // Find new tail
        temp = head;

        for(int i = 0; i < n - k - 1; i++) {
            temp = temp->next;
        }

        // New head
        ListNode* newHead = temp->next;

        // Break the list
        temp->next = nullptr;

        // Connect old tail to old head
        temp = newHead;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;

        return newHead;
    }
};