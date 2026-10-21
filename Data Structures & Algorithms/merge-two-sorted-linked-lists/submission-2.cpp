class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // Loop as long as BOTH lists have nodes to compare
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val <= ptr2->val) {
                curr->next = ptr1;   
                ptr1 = ptr1->next;   
            } else {
                curr->next = ptr2;   
                ptr2 = ptr2->next;   
            }
            curr = curr->next;       
        }

        // If one list runs out, attach the remainder of the other list directly
        if (ptr1 != nullptr) {
            curr->next = ptr1;
        } else {
            curr->next = ptr2;
        }

        return dummy.next;
    }
};
