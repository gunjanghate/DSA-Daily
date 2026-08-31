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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (!head || !head->next || !head->next->next)
            return {-1, -1};
        ListNode* curr = head->next;
        ListNode* nextt = head->next->next;
        ListNode* prev = head;

        int mndiff = INT_MAX, mxdiff = INT_MIN;
        int mn = -1, mx1 = -1, mx2 = -1;

        int i = 1;

        while (nextt) {
            if (curr->val > prev->val && curr->val > nextt->val) {

                if (mn == -1) {
                    mn = i;
                    mx2 = i;
                } else {
                    mx1 = mx2;
                    mx2 = i;

                    if (mndiff == INT_MAX) {
                        mndiff = mx2 - mx1;
                    } else {
                        mndiff = min(mndiff, mx2 - mx1);
                    }
                }
            } else if (curr->val < prev->val && curr->val < nextt->val) {
                if (mn == -1) {
                    mn = i;
                    mx2 = i;
                } else {
                    mx1 = mx2;
                    mx2 = i;

                    if (mndiff == INT_MAX) {
                        mndiff = mx2 - mx1;
                    } else {
                        mndiff = min(mndiff, mx2 - mx1);
                    }
                }
            }
            i++;
            nextt = nextt->next;
            curr = curr->next;
            prev = prev->next;
        }

        // cout<<i<<endl;
        if(mx2==mn) return {-1, -1};
        mxdiff = mx2 - mn;
        return {mndiff, mxdiff};
    }
};