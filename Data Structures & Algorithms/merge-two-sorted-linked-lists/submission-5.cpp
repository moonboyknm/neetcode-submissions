class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        while (ptr1 != nullptr && ptr2 != nullptr){
            if (ptr1->val <= ptr2->val){
                curr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }

        if (ptr1 != nullptr){ // if one list runs out.
            curr->next = ptr1;
        } else {
            curr->next = ptr2; // attach the remaining as is.
        }

        return dummy.next;
    }
};
