#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class my_15ms_Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//先遍历链表计算出链表长度
		if (head == NULL || head->next == NULL)return NULL;
		int length = 0;
		ListNode* p = head;
		while (p != NULL) {
			length++;
			p = p->next;
		}
		p = head;
		n = length - n;
		if (n == 0) {
			head = head->next;
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				p = p->next;
			}
			p->next = p->next->next;
		}
		return head;
	}
};


class sample_6ms_Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		queue<ListNode*>node_queue;
		ListNode* pNode = head;
		if (head == NULL)return head;
		int idx;
		for (idx = 0; pNode != NULL; idx++) {
			if (idx >= n)
				break;
			node_queue.push(pNode);
			pNode = pNode->next;
		}
	}
};