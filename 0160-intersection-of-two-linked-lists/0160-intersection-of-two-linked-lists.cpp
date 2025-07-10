/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int size(ListNode* head){
        ListNode* temp = head;
        int s = 0;
        while(temp){
            s++;
            temp = temp->next;
        }

        return s;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* temp1 = headA; 
        ListNode* temp2 = headB;
        // unordered_map<ListNode*, int> mp;
        // while(temp2){
        //     mp[temp2] = 1;
        //     temp2 = temp2->next;
        // }
        // while(temp1){
        //     if(mp[temp1]){
        //         return temp1;
        //     }
        //     temp1 = temp1->next;
        // }

        // return NULL; 
        int s1 = size(temp1);
        int s2 = size(temp2);
        int d;
        if(s1>s2){
            d = s1-s2;
        }else{
            d = s2-s1;
        }
        while(d){
            if(s1>s2){
                temp1 = temp1->next;
                d--;
            }else{
                temp2 = temp2->next;
                d--;
            } 
        }
        while(temp1 && temp2){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;

        }
            
};