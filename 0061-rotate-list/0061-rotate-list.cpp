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
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head || !head->next) return head;
        int size = 0;
        ListNode* sizeptr = head;
        while(sizeptr){
            size++;
            sizeptr = sizeptr->next;
        }
        k = k % size;
        if(k==0) return head;
        int l = size - k;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp){
            if(l==0) break;
            l--;
            prev = temp;
            temp = temp->next;
        }
        ListNode* end = temp;
        while(end && end->next){
            end = end->next;
        }
        end->next = head;
        prev->next = NULL;
        head = temp;


        return head;
    }
};