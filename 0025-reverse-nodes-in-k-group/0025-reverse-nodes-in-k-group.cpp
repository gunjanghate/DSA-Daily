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
    ListNode* findKthNode(ListNode* head, int k) {
        ListNode* temp = head;
        k -= 1;
        while (temp && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp) {
            ListNode* Kthnode = findKthNode(temp, k);
            if (!Kthnode) {
                if (prev)
                    prev->next = temp;
                break;
            }
            ListNode* nextNode = Kthnode->next;
            Kthnode->next = nullptr;
            reverse(temp);
            if (head == temp) {
                head = Kthnode;
            } else {
                prev->next = Kthnode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};