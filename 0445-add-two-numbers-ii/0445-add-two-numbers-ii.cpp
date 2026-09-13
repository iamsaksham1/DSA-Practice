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
   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1,st2;
        while(l1){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2=l2->next;
        }
        ListNode* res=NULL;
        int carry=0;
        while(st1.size() && st2.size()){
            int val =st1.top()+st2.top()+carry;
            carry=val/10;
            val%=10;
            ListNode* temp=new ListNode(val);
            st1.pop();st2.pop();
            temp->next=res;
            res=temp;
        }
        while(st1.size()!=0){
            int val =st1.top()+carry;
            carry=val/10;
            val%=10;
            ListNode* temp=new ListNode(val);
            st1.pop();
            temp->next=res;
            res=temp;
        }
         while(st2.size()){
            int val =st2.top()+carry;
            carry=val/10;
            val%=10;
            ListNode* temp=new ListNode(val);
           st2.pop();
            temp->next=res;
            res=temp;
        }
        if(carry){
             ListNode* temp=new ListNode(carry);
            temp->next=res;
            res=temp;
        }
        return res;


       
    }
};