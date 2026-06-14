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
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondPart = reverse(slow->next);

        ListNode* firstPart = head;

        int ans = INT_MIN;

        while(secondPart){
            ans = max(ans, firstPart->val + secondPart->val);

            firstPart = firstPart->next;
            secondPart = secondPart->next;
        }

        return ans;
    }
};