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

ListNode* middleNode(ListNode* head) {
        
        ListNode *hare,*tortoise;
        hare = tortoise = head;
        
        while(hare && hare->next)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        return tortoise;
    }

int main(){

    

    return 0;
}