/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* temp1 = headA; 
        ListNode* temp2 = headB;
        unordered_map<ListNode*, int> mp;
        while(temp2){
            mp[temp2] = 1;
            temp2 = temp2->next;
        }
        while(temp1){
            if(mp[temp1]){
                return temp1;
            }
            temp1 = temp1->next;
        }

        return NULL; 
    }
};