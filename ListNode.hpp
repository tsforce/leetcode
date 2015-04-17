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

ListNode * NewList() {
    ListNode *h = new ListNode(2);
    ListNode *p = h;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(8);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(9);
    p = p->next;
    p->next = new ListNode(8);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;
    return h;
}
