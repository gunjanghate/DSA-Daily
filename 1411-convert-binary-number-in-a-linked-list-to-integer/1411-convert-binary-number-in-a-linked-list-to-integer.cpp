class Solution {
public:
    // int getDecimalValue(ListNode* head) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);

    //     int result = 0;
    //     ListNode* temp = head;

    //     while (temp != nullptr) {
    //         result = result * 2 + temp->val;
    //         temp = temp->next;
    //     }

    //     return result;
    // }
    int getDecimalValue(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int result = 0;
        while (head) {
            result = (result << 1) | head->val; 
            head = head->next;
        }

        return result;
    }
};

    // Step 1:
    // head->val = 1
    // result << 1 = 0 << 1 = 0
    // 0 | 1 = 1
    // result = 1

    // Step 2:
    // head->val = 0
    // result << 1 = 1 << 1 = 2 (binary 10)
    // 2 | 0 = 2
    // result = 2

    // Step 3:
    // head->val = 1
    // result << 1 = 2 << 1 = 4 (binary 100)
    // 4 | 1 = 5 (binary 101)
    // result = 5