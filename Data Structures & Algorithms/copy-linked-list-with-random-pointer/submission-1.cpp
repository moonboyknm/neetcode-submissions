class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> cloneMap;

        // Pass 1: Clone all nodes and store the address mapping
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            cloneMap[curr] = new Node(curr->val);
        }

        // Pass 2: Connect next and random pointers using map lookups
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            cloneMap[curr]->next = cloneMap[curr->next];
            cloneMap[curr]->random = cloneMap[curr->random];
        }

        return cloneMap[head];
    }
};