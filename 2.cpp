#include<iostream>
#include<vector>
#include<map>
#include "ListNode.hpp"
using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	if(l1 == NULL && l2 == NULL)
		return NULL;
	ListNode *p = l1, *q = l2;
	int val = 0;
	if(p) {
		val += p->val;
        p = p->next;
    }
	if(q) {
		val += q->val;
        q = q->next;
    }
	bool flag = val / 10;
	val %= 10;
	ListNode *h = new ListNode(val);
	ListNode *l = h;
	while(p || q) {
		val = flag ? 1 : 0;
        if(p) {
            val += p->val;
            p = p->next;
        }
        if(q) {
            val += q->val;
            q = q->next;
        }
		flag = val / 10;
		val %= 10;
		l->next = new  ListNode(val);
		l = l->next;
	}
    if(flag)
        l->next = new ListNode(1);
    return h;
}

int main(){
    int a[] = {1,4,13,34}; 
    int *p = a;
    cout<<*p<<endl;
    int v = ++*p;
    cout<<v<<endl;
    v = ++*p;
    cout<<v<<endl;
    v = ++*p;
    cout<<v<<endl;
	return 1;
}
