//
// Created by y2295 on 2026/9/17.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev=nullptr;
    ListNode* cur=head;
    while (cur!=nullptr) {
        ListNode* nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next =new ListNode(2);
    head->next->next =new ListNode(3);
    head->next->next->next =new ListNode(4);
    head->next->next->next->next =new ListNode(5);
    for (ListNode* p=head;p!=nullptr;p=p->next) {
        cout<<p->val;
        if (p->next!=nullptr) {
            cout<<"->";
        }
    }
    cout<<endl;
    head = reverseList(head);
    if (head!=nullptr) {
        cout<<head->val;
        for (ListNode* p=head->next;p!=nullptr;p=p->next) {
        cout<<"->"<<p->val;
    }
    }

    return 0;
}

