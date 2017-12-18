#include<iostream>
#include<algorithm>
using namespace std;


 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)return NULL;
		//先用垃圾一点的方法，即对原链表进行遍历
		ListNode* real_head = new ListNode(0);
		real_head->next = head;
		ListNode* behind = head->next,*pre=real_head;
		int flag = 1;
		while (head != NULL) {
			if (behind == NULL)break;
			if (flag == 1) {
				flag = 0;
				real_head->next = behind;
				head->next = behind->next;
				behind->next = head;
				pre = head;
				head = head->next;
				if (head == NULL) {
					break;
				}
				else {
					behind = head->next;
				}
			}
			else {
				pre->next = behind;
				head->next = behind->next;
				behind->next = head;
				pre = head;
				head = head->next;
				if (head == NULL) {
					break;
				}
				else {
					behind = head->next;
				}
			}
		}
		return real_head->next;
	}
};