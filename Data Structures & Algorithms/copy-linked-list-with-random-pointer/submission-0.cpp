/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create a dummy head for the new linked list
        Node* dummyHead = new Node(0);
        Node* currentNewNode = dummyHead;
      
        // Hash map to store mapping from original nodes to their copies
        unordered_map<Node*, Node*> originalToCopy;
      
        // First pass: Create all nodes and establish next pointers
        for (Node* currentOriginal = head; currentOriginal != nullptr; currentOriginal = currentOriginal->next) {
            // Create a copy of the current node
            Node* copiedNode = new Node(currentOriginal->val);
          
            // Link the new node to the new list
            currentNewNode->next = copiedNode;
            currentNewNode = copiedNode;
          
            // Store the mapping from original to copy
            originalToCopy[currentOriginal] = copiedNode;
        }
      
        // Second pass: Set up random pointers using the mapping
        for (Node* currentOriginal = head; currentOriginal != nullptr; currentOriginal = currentOriginal->next) {
            // If original node has a random pointer, set the corresponding random pointer in the copy
            if (currentOriginal->random != nullptr) {
                originalToCopy[currentOriginal]->random = originalToCopy[currentOriginal->random];
            } else {
                originalToCopy[currentOriginal]->random = nullptr;
            }
        }
      
        // Return the head of the copied list (skip dummy node)
        return dummyHead->next;
    }
};
