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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a=0;
        ListNode* curr=head;
        while(curr){
            a++;
            curr=curr->next;
        }
        if(n==a){head=head->next;return head;}
                a-=n;
        a--;
        curr=head;
        cout<<a<<endl;
        while(a--){
            curr=curr->next;
        }

      curr->next=curr->next->next;
        return head;
    }
};