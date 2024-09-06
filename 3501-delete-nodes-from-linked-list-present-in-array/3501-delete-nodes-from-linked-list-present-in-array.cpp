class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> a(nums.begin(), nums.end());

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            if (a.count(curr->val)) {
                if (prev != nullptr) {
                    prev->next = curr->next;  // bypass current node
                } else {
                    head = curr->next;  // update head if the first node is to be removed
                }
                curr = curr->next;  // move to the next node after deletion
            } else {
                prev = curr;  // move prev to current node
                curr = curr->next;  // move to the next node
            }
        }
        
        return head;
    }
};
