#include <iostream>
using namespace std;

struct ListNode {
   int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr, *cur = head, *ptr = head;
		while (cur != nullptr)
		{
			ptr = cur->next;
			cur->next = pre;
			pre = cur;
			cur = ptr;
		}

		return pre;
    }
};


