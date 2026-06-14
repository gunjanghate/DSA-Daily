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

        while(temp!=NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* mid = slow;
        ListNode* newPart = slow->next;
        slow->next = NULL;

        ListNode* firstPart = reverse(temp);

        int ans = INT_MIN;
        while(firstPart && newPart){
            ans = max(ans, firstPart->val + newPart->val);
            firstPart = firstPart -> next;
            newPart = newPart -> next;
        }


        return ans;

    }
};