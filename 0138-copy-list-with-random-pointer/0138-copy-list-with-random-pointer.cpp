/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            // Create a new node with the same data
            Node* copy = new Node(temp->val);

            // Point the copy's next to
            // the original node's next
            copy->next = nextElement;

            // Point the original
            // node's next to the copy
            temp->next = copy;

            // Move to the next original node
            temp = nextElement;
        }
    }

    // Function to connect random
    // pointers of the copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            // Access the copied node
            Node* copyNode = temp->next;

            // If the original node
            // has a random pointer
            if (temp->random) {
                // Point the copied node's random to the
                // corresponding copied random node
                copyNode->random = temp->random->next;
            } else {
                // Set the copied node's random to
                // null if the original random is null
                copyNode->random = NULL;
            }

            // Move to the next original node
            temp = temp->next->next;
        }
    }

    // Function to retrieve the
    // deep copy of the linked list

Node* copyRandomList(Node* head) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!head) return nullptr;

    // Step 1: Insert copied nodes in between
    insertCopyInBetween(head);

    // Step 2: Connect the random pointers
    connectRandomPointers(head);

    // Step 3: Separate the copied list
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* copyTail = dummyNode;

    while (temp) {
        Node* copyNode = temp->next;
        copyTail->next = copyNode;
        copyTail = copyNode;

        temp->next = copyNode->next; // Restore original list
        temp = temp->next;
    }

    return dummyNode->next;
}

};