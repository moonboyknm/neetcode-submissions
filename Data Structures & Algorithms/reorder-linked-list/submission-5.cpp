/*
Var Legend:
    sHH : secondHalfHead
    fHC : firstHalfHead
    sHC : secondHalfHead
    fHN : firstHalfNext
*/

class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* sHH = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = sHH;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }

        ListNode* fHC = head;
        ListNode* sHC = prev;

        while (sHC){
            ListNode* fHN = fHC->next;
            ListNode* sHN = sHC->next;

            fHC->next = sHC;
            sHC->next = fHN;

            fHC = fHN;
            sHC = sHN;
            
        }
    }
};
