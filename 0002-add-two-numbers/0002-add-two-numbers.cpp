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
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        return size;
    }
    ListNode* appendZeros(ListNode* list, int diff) {

        ListNode* temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (diff--) {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        return list;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n1 = sizeOfLL(l1);
        int n2 = sizeOfLL(l2);
        if (n1 > n2) {
            l2 = appendZeros(l2, n1 - n2);
        } else if (n2 > n1) {
            l1 = appendZeros(l1, n2 - n1);
        }

        ListNode* ans = n1>n2 ? l1 : l2;
        ListNode* res = ans;
        ListNode* prevRes = ans;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        while (t1 != NULL && t2 != NULL) {
            int s = t1->val + t2->val + carry;
            if (s > 9)
                carry = 1;
            else
                carry = 0;
            res->val = s % 10;
            prevRes = res;
            res = res->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(carry){
            ListNode* carryNode = new ListNode(carry);
            prevRes->next = carryNode;
        }

        return ans;
    }
};