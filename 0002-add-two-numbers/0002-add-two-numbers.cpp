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
    // // Get size of linked list
    // int sizeOfLL(ListNode* head) {
    //     int size = 0;
    //     while (head) {
    //         size++;
    //         head = head->next;
    //     }
    //     return size;
    // }

    // // Append 'diff' number of 0s at the end of the list
    // ListNode* appendZeros(ListNode* list, int diff) {
    //     ListNode* temp = list;
    //     while (temp->next) temp = temp->next;
    //     while (diff--) {
    //         temp->next = new ListNode(0);
    //         temp = temp->next;
    //     }
    //     return list;
    // }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // int n1 = sizeOfLL(l1);
        // int n2 = sizeOfLL(l2);
        // if (n1 > n2) l2 = appendZeros(l2, n1 - n2);
        // else if (n2 > n1) l1 = appendZeros(l1, n2 - n1);

        // ListNode* ans = new ListNode(0); 
        // ListNode* res = ans;
        // int carry = 0;

        // while (l1 && l2) {
        //     int sum = l1->val + l2->val + carry;
        //     carry = sum / 10;
        //     res->next = new ListNode(sum % 10);
        //     res = res->next;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }

        // if (carry)
        //     res->next = new ListNode(carry);

        // return ans->next;  // skip dummy node

        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 

    }
};