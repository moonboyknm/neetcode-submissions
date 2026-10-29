class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy; ListNode* slow = dummy;
        while (n--) fast = fast->next;
        while (fast->next){ slow = slow->next; fast = fast->next; }
        ListNode* todel = slow->next;
        slow->next = slow->next->next;
        delete todel;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};