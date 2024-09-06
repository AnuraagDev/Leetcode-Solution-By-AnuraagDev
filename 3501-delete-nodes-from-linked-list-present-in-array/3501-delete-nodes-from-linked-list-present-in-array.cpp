class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> a(nums.begin(), nums.end());

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (a.count(curr->val)) {
                if (prev != nullptr) {
                    prev->next = curr->next;  
                } else {
                    head = curr->next;  
                }
                curr = curr->next;
            } else {
                prev = curr;  
                curr = curr->next; 
            }
        }
        
        return head;
    }
};
