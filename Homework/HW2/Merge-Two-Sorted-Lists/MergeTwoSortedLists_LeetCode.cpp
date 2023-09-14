// Name: Aidan Cowan
// Date: 9/6/23
// Program: ECGR 3180 - Homework 2 LeetCode: Merge Two Sorted Lists
// Description:
// 
// You are given the heads of two sorted linked lists list1 and list2. 
// Merge the two lists into one sorted list.
// The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list2 != NULL) {
            head->next = list2;
        }
        if (list1 != NULL) {
            head->next = list1;
        }
        return temp->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){
    Solution solution;

    ListNode* list1 = new ListNode(1);
    ListNode* list2 = new ListNode(4);

    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    list2->next = new ListNode(5);
    list2->next->next = new ListNode(6);


    cout << "List 1: ";
    printList(list1);

    cout << endl << "List 2: ";
    printList(list2);

    ListNode* list3 = solution.mergeTwoLists(list1, list2);

    cout << endl << "List 3: ";
    printList(list3);

    return 0;
}