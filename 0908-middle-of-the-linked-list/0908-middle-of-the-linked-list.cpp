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
    int sizeOfLL(ListNode*head){
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        return size;
    }
public:
    ListNode* middleNode(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = sizeOfLL(head);
        int mid = n/2 + 1;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            if(cnt==mid){
                break;
            }
            temp = temp->next;
        }

        return temp;
    }
};