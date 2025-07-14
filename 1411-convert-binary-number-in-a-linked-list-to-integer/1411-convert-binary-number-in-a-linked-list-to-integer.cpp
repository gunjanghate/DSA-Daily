class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int result = 0;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            result = result * 2 + temp->val; 
            temp = temp->next;
        }
        
        return result;
    }
};
