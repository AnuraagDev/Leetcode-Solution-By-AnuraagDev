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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr=head;
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* currn=head->next;
        while(currn!=nullptr){
            swap(curr->val,currn->val);
            if(currn->next==nullptr)break;
            curr=curr->next->next;
            currn=currn->next->next;
        }
        return head;
    }
};