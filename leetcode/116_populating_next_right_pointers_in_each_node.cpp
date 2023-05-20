#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {

    Node * curr = root;
    Node * nxt = root ? root->left:NULL;

    while (curr && nxt){
        curr->left->next = curr->right;
        curr->right->next = curr->next ? curr->next->left:NULL;

        if (curr->next){ // search along breadth
            curr = curr->next;
        }
        else { // search along depth
            curr = nxt;
            nxt = nxt->left;
        }

    }

    return root;
    
}

void print_tree(Node * t){
    if (t==NULL){
        return;
    }
    int val = t->val;
    char next_ = t->next?'>':'.';
    std::cout<<val<<" "<<next_<<std::endl;
    print_tree(t->left);
    print_tree(t->right);
}

int main(){

    Node a4 = Node(4);
    Node a5 = Node(5);
    Node a6 = Node(6);
    Node a7 = Node(7);
    Node a2 = Node(2, &a4, &a5, NULL);
    Node a3 = Node(3, &a6, &a7, NULL);
    Node a1 = Node(1, &a2, &a3, NULL);

    print_tree(&a1);

    connect(&a1);

    std::cout<<"----"<<std::endl;

    print_tree(&a1);


    return 0;
}