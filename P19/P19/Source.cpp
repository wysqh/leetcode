#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Given a linked list, remove the nth node from the end of list and return its head.

	For example,

	   Given linked list: 1->2->3->4->5, and n = 2.

	   After removing the second node from the end, the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
*/

//45.28%

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *ptr = head, *ajt = nullptr, *tmp = head;
		int sum = 0;
		while (tmp != nullptr)
		{
			sum++;
			tmp = tmp->next;
		}
		int node  = sum - n >= 0 ? sum - n : 0, i = 0;
		if (node == 0)
		{
			ListNode *newHead = head->next;
			head->next = nullptr;
			delete head;
			return newHead;
		}

		while (i < node)
		{
			ajt = ptr;
			ptr = ptr->next;
			i++;
		}
		ajt->next = ptr->next;
		delete ptr;
		return head;
    }
};

int main()
{

	return 0;
}