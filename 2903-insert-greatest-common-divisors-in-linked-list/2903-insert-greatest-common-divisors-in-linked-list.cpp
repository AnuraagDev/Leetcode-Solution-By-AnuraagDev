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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* curr=head;
        ListNode* curr1=head->next;
        while(curr1!=nullptr){
            int a=gcd(curr1->val,curr->val);
            ListNode* ne=new ListNode(a);
            ne->next=curr->next;
            curr->next=ne;
            curr=curr1;
            curr1=curr1->next;

        }return head;
    }
};