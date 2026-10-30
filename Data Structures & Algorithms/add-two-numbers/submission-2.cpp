class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode dummy(-1);
       ListNode* curr = &dummy;

       ListNode* t1 = l1;
       ListNode* t2 = l2;
       int carry = 0;

       while (t1 || t2){
            int sum = carry;

            if (t1){
                sum += t1->val;
                t1 = t1->next;
            }

            if (t2){
                sum += t2->val;
                t2 = t2->next;
            }

            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        if (carry > 0){
            curr->next = new ListNode(carry);
        } 

        return dummy.next;
    }
};
