#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include "ListNode.hpp"
using namespace std;
ListNode* swapPairs(ListNode* head) {
  if(head == NULL)
    return NULL;
  ListNode *p1 = head;
  ListNode *p2 = head->next;
  if(p2 == NULL)
    return p1;
  ListNode d(2);
  ListNode *t = &d;
  while(p1 && p1->next) {
    t->next = p1->next;
    p2 = p1->next->next;
    t->next->next = p1;
    t = p1;
    p1 = p2;
  }
  t->next = p1;
  return d.next;
}



int main(){
	return 1;
}
