class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;
        
        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head; 
            check = check->next;
        }
        while (count < k && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) {
            head->next = reverse(next, k); 
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;

        while (temp) {
            temp = temp->next;
            count++;
        }


        if (count < k) {
            return head;
        }

        return reverse(head, k);
    }
};
