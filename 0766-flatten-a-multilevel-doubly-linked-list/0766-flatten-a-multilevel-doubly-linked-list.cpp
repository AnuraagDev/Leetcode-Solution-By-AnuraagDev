class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* childTail = findTail(curr->child);
                
                if (curr->next != nullptr) {
                    curr->next->prev = childTail;
                }
                
                childTail->next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        
        return head;
    }

private:
    Node* findTail(Node* head) {
        while (head->next != nullptr) {
            head = head->next;
        }
        return head;
    }
};
