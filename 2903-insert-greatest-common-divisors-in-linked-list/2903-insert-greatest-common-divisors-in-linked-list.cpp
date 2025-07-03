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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ListNode* prev = head;
        ListNode* post = head->next;
        int i = 0;
        while (post != NULL) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int gcdValue = __gcd(prev->val, post->val);

            ListNode* newNode = new ListNode(gcdValue);

            prev->next = newNode;
            newNode->next = post;

            prev = post;
            post = post->next;
        }
        return head;
    }
};