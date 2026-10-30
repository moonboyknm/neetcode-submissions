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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Stack-allocated dummy node avoids manual heap allocation and memory leak
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;

        // Traverse while either list has remaining digits
        while (t1 != nullptr || t2 != nullptr) {
            int sum = carry;

            if (t1 != nullptr) {
                sum += t1->val;
                t1 = t1->next;
            }

            if (t2 != nullptr) {
                sum += t2->val;
                t2 = t2->next;
            }

            // Create new digit node and update carry
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        // If a carry remains after both lists are exhausted
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return dummy.next;
    }
};