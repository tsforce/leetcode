#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include "ListNode.hpp"
using namespace std;
ListNode* reverse(ListNode* head, int k) {
  cout<<"reverst"<<*head<<endl;
  ListNode d(0), *p;
  while(k--) {
    p = head->next;
    head->next = d.next;
    d.next = head;
    head = p;
  }
  return d.next;
}
ListNode* reverseKGroup(ListNode* head, int k) {
  if(head == NULL || k <2)
    return head;
  ListNode d(0);
  ListNode *h = &d;
  h->next=head;
  while(h->next) {   
    ListNode *p1 = h->next;
  cout<<"whiel"<<*p1<<endl;
    ListNode *p2 = p1;
    ListNode *p3;
    int n = 1;
    while(n++ < k){
      p2 = p2->next;
      if(p2 == NULL)
        return d.next;
    }
    p3 = p2->next;
    reverse(p1, k);
    h->next = p2;
    p1->next = p3;
    h = p1;
  }
  return d.next;
}


int main(){
  ListNode *h = NewList(5);
  cout<<*h<<endl;
    cout<<*reverseKGroup(h, 2);
	return 1;
}
