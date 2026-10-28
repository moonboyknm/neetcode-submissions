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
    /**
     * Remove the nth node from the end of a linked list
     * @param head: pointer to the head of the linked list
     * @param n: position from the end (1-indexed)
     * @return: pointer to the head of the modified linked list
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node pointing to head to handle edge cases
        // (e.g., removing the head node)
        ListNode* dummyNode = new ListNode(0, head);
      
        // Initialize two pointers for the two-pointer technique
        ListNode* fastPointer = dummyNode;
        ListNode* slowPointer = dummyNode;
      
        // Move fast pointer n steps ahead
        // This creates a gap of n nodes between fast and slow pointers
        while (n--) {
            fastPointer = fastPointer->next;
        }
      
        // Move both pointers simultaneously until fast reaches the last node
        // When fast reaches the end, slow will be at the node before the target
        while (fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
      
        // Remove the nth node from the end by skipping it
        // slowPointer is now at the node before the one to be removed
        ListNode* nodeToDelete = slowPointer->next;
        slowPointer->next = slowPointer->next->next;
      
        // Clean up memory (optional but good practice)
        delete nodeToDelete;
      
        // Store the actual head before deleting dummy
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
      
        return newHead;
    }
};

