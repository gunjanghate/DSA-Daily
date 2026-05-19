class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != NULL){

            ListNode* front = temp->next; // save next node

            temp->next = prev;            // reverse link

            prev = temp;                  // move prev ahead

            temp = front;                 // move temp ahead
        }

        return prev;
    }
};