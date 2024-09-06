#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* reverseList(ListNode* head) {
     // recursive

     if(head==NULL || head->next==NULL) return head;

     ListNode* newhead = reverseList(head->next);

     head->next->next = head;
     head->next = NULL;

     return newhead;


     // iterative
     
     ListNode* prev = NULL;
     while(head){
        ListNode* next = head->next;
        head->next=prev;
        prev = head;
        head = next;
     }

     return prev;
       
    }