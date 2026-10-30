class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> cloneMap;

        for (Node* curr = head; curr != nullptr; curr = curr->next){
            cloneMap[curr] = new Node(curr->val);
        }

        for (Node* curr = head; curr != nullptr; curr = curr->next){
            cloneMap[curr]->next = cloneMap[curr->next];
            cloneMap[curr]->random = cloneMap[curr->random];
        }

        return cloneMap[head];
    }
};
