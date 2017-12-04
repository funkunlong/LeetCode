#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 != NULL) {
			return l2;
		}
		if (l1 != NULL && l2 == NULL) {
			return l1;
		}
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		ListNode *pre = new ListNode(0); ListNode *head = l1;
		while (l2!=NULL&&l2->val < head->val) {
			ListNode *tmp = new ListNode(l2->val);
			tmp->next = head;
			head = tmp;
			l1 = head;
			l2 = l2->next;
		}
		while (l1 != NULL&&l2 != NULL) {
			if (l1->val <= l2->val&&l1->next!=NULL&&l1->next->val>=l2->val) {
				ListNode *tmp = new ListNode(l2->val);
				tmp->next = l1->next;
				l1->next = tmp;
				pre = l1;
				l1 = l1->next;
				l2 = l2->next;
			}
			else {
				pre = l1;
				l1 = l1->next;
			}
		}
		if (l2 != NULL) {
			pre->next = l2;
		}
		return head;
	}
};