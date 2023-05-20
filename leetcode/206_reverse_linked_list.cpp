#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode * list){
    while(list!=NULL){
        std::cout<<list->val<<" ";
        list = list->next;
    }
    std::cout<<std::endl;
}

ListNode* reverseList(ListNode* head) {

    if (head==NULL || head->next==NULL){
        return head;
    }

    
    ListNode * h;
    ListNode * c;
    ListNode * n;

    h = head;
    c = head->next;
    n = head->next->next;

    while (c!=NULL){
        if (n!=NULL){

            std::cout<<"a"<<std::endl;
            c->next = h;
            h=c;
            c=n;
            n=n->next;
        }

        else {
            std::cout<<"b"<<std::endl;
            c->next = h;
            break;
            // h=c;
            // c=n;
            // head->next = NULL;
            // return c;
        }

    }

    head->next = NULL;

    return c;

}

int main(){

    ListNode a5 = ListNode(5);
    ListNode a4 = ListNode(4, &a5);
    ListNode a3 = ListNode(3, &a4);
    ListNode a2 = ListNode(2, &a3);
    ListNode a1 = ListNode(1, &a2);

    print_list(&a1);

    // ListNode * rev = reverseList(&a1);
    // ListNode * rev = reverseList(NULL);
    ListNode * rev = reverseList(&a5);

    print_list(rev);


    return 0;
}