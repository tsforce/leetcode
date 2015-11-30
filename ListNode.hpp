#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ostream& operator<<(ostream& os, const ListNode& n) {
    os << n.val;
    if(n.next) {
        os << " -> " << *n.next;
    }
    else 
        os << ";";
}

ListNode * NewList(int n) {
    ListNode d(0), *h = &d;
    for(int i = 1; i <= n; ++i) {
      ListNode *p =  new ListNode(i);
      h->next = p;
      h = p;
    }
    h->next = NULL;
    return d.next;
}
