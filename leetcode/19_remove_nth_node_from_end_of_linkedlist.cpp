#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode dummy = ListNode(-1, head);
    ListNode *prev = &dummy;
    ListNode *Lptr = head;
    ListNode *Rptr = head;
    int steps = 0;

    for(int i=0; i<n; i++){
        Rptr = Rptr->next;
    }

    
    // std::cout<<"Prev: "<<prev->val<<std::endl;
    // std::cout<<"Lptr: "<<Lptr->val<<std::endl;
    // std::cout<<"Rptr: "<<Rptr->val<<std::endl;

    while(Rptr!=NULL){
        Rptr = Rptr->next;
        Lptr = Lptr->next;
        prev = prev->next;
        steps++;
    }

    // std::cout<<"Prev: "<<prev->val<<std::endl;
    // std::cout<<"Lptr: "<<Lptr->val<<std::endl;


    prev->next = prev->next->next;

    return dummy.next;
   

}


int main(){

    ListNode e = ListNode(5);
    ListNode d = ListNode(4, &e);
    ListNode c = ListNode(3, &d);
    ListNode b = ListNode(2, &c);
    ListNode a = ListNode(1, &b);

    // ListNode b = ListNode(2);
    // ListNode a = ListNode(1, &b);

    // ListNode a = ListNode(100);

    ListNode *ptr = removeNthFromEnd(&a,1);


    while (ptr!=NULL){
        std::cout<<ptr->val<<std::endl;
        ptr = ptr->next;
    }



    
    
    return 0;
}