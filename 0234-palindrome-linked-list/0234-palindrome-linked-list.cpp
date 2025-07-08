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
    // bool isPalindrome(ListNode* head) {
    //     ListNode* temp = head;
    //     stack<int> st;
    //     while(temp!=NULL){
    //         st.push(temp->val);
    //         temp=temp->next;
    //     }

    //     ListNode* t = head;
    //     while(t!=NULL){
    //         if(t->val!=st.top()){
    //             return false;
    //         }
    //         st.pop();
    //         t = t->next;
    //     }

    //     return true;
    // } sc- O(n)
    ListNode* reverse(ListNode* head) {
        ListNode* rev = nullptr;
        while (head != NULL) {
            ListNode* temp = head->next;
            head->next = rev;
            rev = head;
            head = temp;
        }
        return rev;
    }

    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode* slow = head;
        ListNode* fast = head;
        if (head->next == NULL) {
            return true;
        }
        if (head->next->next == NULL) {
            if (head->val == head->next->val)
                return true;
            return false;
        }
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverse(slow->next);
        ListNode* second = newHead;
        ListNode* first = head;
        while (second != NULL && first != NULL) {
            if (first->val != second->val) {
                reverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(newHead);

        return true;
    }
};