#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = new ListNode(0);
		ListNode* p = head;
		
		vector<int>tmp_vector;
		//��ʹ������ķ�ʽ��һ�£������еĵ�ȡ�����Ž�vector�У�Ȼ������������֮��������װ��һ������
		for (int i = 0; i < lists.size(); i++) {
			while (lists[i] != NULL) {
				tmp_vector.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		if (tmp_vector.empty())return NULL;
		sort(tmp_vector.begin(), tmp_vector.end());

		int len = tmp_vector.size();
		for (int i = 0; i < len-1; i++) {
			p->val = tmp_vector[i];
			p->next=new ListNode(0);
			p = p->next;
		}
		p->val = tmp_vector[len-1];
		return head;
	}
};