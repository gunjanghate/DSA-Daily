class Solution {
public:

    Node* solve(Node* head){

        Node* curr = head;
        Node* last = head;

        while(curr){

            Node* nextNode = curr->next;
            if(curr->child){

                Node* childHead = curr->child;
                Node* childTail = solve(childHead);

                // connect current -> child
                curr->next = childHead;
                childHead->prev = curr;

                // connect child tail -> next
                if(nextNode){
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                curr->child = nullptr;

                last = childTail;
            }
            else{
                last = curr;
            }

            curr = nextNode;
        }

        return last;
    }

    Node* flatten(Node* head) {

        if(!head) return head;

        solve(head);

        return head;
    }
};