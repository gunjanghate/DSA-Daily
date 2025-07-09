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
    int sizeOfLL(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

        return size;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = sizeOfLL(head);

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int k = l - n + 1;
        if (k == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int i = 1;
        while (temp) {
            if (i == k) {
                ListNode* t = temp;
                prev->next = t->next;
                delete t;
                break;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }

        return head;
    }
};