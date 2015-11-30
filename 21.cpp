#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include "ListNode.hpp"
using namespace std;
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if(l1 == NULL)
    return l2;
  else if(l2 == NULL)
    return l1;
  ListNode *p1 = l1, *p2 = l2, *h, *head;
  if(p1->val < p2->val) {
    h = p1;
    p1 = p1->next;
  } else {
    h= p2;
    p2 = p2->next;
  }
  head = h;
  while(p1 && p2) {
    if(p1->val < p2->val) {
      h->next = p1;
      p1 = p1->next;
    } else {
      h->next = p2;
      p2 = p2->next;
    }
    h = h->next;
  }
  if(p1)
    h->next = p1;
  if(p2)
    h->next = p2;
  return head;
}


int main(){
	return 1;
}
