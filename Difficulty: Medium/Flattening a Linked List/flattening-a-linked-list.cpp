/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* mergeLists(Node* list1 , Node* list2){
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data <= list2->data){
                res->bottom = list1;
                res= list1;
                list1 = list1->bottom;
            }else{
                res->bottom = list2;
                res= list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }
            if(list1){
                res->bottom = list1;
            }else{
                res->bottom = list2;
            }
        if(dummy->bottom){
            dummy->bottom->next = NULL;
        }
            
            
            return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr || root->next==nullptr){
            return root;
        }
        Node* mergedHead = flatten(root->next);
        return mergeLists(root, mergedHead);
        
    }
};