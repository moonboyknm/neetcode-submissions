class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Dummy node sits before the real head of our merged list.
        // Using stack allocation (ListNode dummy(0)) avoids memory leaks, 
        // or you can use `new ListNode(0)`.
        ListNode* dummy = new ListNode(0);
        
        // 2. `curr` is the tail of our new merged list. It starts at dummy.
        ListNode* curr = dummy;

        // 3. Point ptr1 and ptr2 to the actual heads of the two lists.
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // 4. Loop as long as BOTH lists have nodes to compare
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val <= ptr2->val) {
                curr->next = ptr1;   // Point current tail to the smaller node
                ptr1 = ptr1->next;   // Move ptr1 ahead
            } else {
                curr->next = ptr2;   // Point current tail to the smaller node
                ptr2 = ptr2->next;   // Move ptr2 ahead
            }
            curr = curr->next;       // Move our merged list's tail ahead by one node
        }

        // 5. If one list runs out, attach the remainder of the other list directly
        if (ptr1 != nullptr) {
            curr->next = ptr1;
        } else {
            curr->next = ptr2;
        }

        // 6. How to return the head:
        // `dummy` never moved! So `dummy->next` points to the very first real node we attached.
        ListNode* head = dummy->next;
        delete dummy; // Clean up the heap-allocated dummy node
        return head;
    }
};
