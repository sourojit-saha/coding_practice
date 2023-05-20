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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode dummy = ListNode();
    ListNode * tail = &dummy;

    while (list1!=NULL && list2!=NULL){
        if (list1->val<=list2->val){
            tail->next = list1;
            list1 = list1->next;
        }

        else{
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    };

    if (list1!=NULL && list2==NULL){
        tail->next = list1;
    }
    else if (list1==NULL && list2!=NULL){
        tail->next = list2;
    }

    return dummy.next;
    
}

int main(){

    ListNode a4 = ListNode(10);
    ListNode a2 = ListNode(2, &a4);
    ListNode a1 = ListNode(1, &a2);

    ListNode b4 = ListNode(4);
    ListNode b3 = ListNode(3, &b4);
    ListNode b1 = ListNode(1, &b3);

    print_list(&a1);
    print_list(&b1);

    ListNode* res = mergeTwoLists(NULL, NULL);
    // ListNode* res = mergeTwoLists(&a1, &b1);

    print_list(res);



    return 0;
}