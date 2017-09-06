#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	Merge two sorted linked lists and return it as a new list. 
	The new list should be made by splicing together the nodes of the first two lists.
*/


//23.02%
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head1 = l1, *head2 = l2;
		ListNode *newHead = nullptr, *ptr = nullptr;
		if (l1 == nullptr && l2 == nullptr)
			return nullptr;

		while (l1 != nullptr && l2 != nullptr)
		{
			if ( l1->val < l2->val)
			{
				if (newHead == nullptr)
				{
					newHead = new ListNode(l1->val);
					ptr = newHead;
				}
				else
				{
					ListNode *node = new ListNode(l1->val);
					ptr->next = node;
					ptr = node;
				}
				l1 = l1->next;
			}
			else
			{
				if (newHead == nullptr)
				{
					newHead = new ListNode(l2->val);
					ptr = newHead;
				}
				else
				{
					ListNode *node = new ListNode(l2->val);
					ptr->next = node;
					ptr = node;
				}
				l2 = l2->next;
			}
		}

		while (l1 != nullptr)
		{
			if (newHead == nullptr)
			{
				newHead = new ListNode(l1->val);
				ptr = newHead;
				l1 = l1->next;
				continue;
			}

			ListNode *node = new ListNode(l1->val);
			ptr->next = node;
			ptr = node;
			l1 = l1->next;
		}

		while (l2 != nullptr)
		{
			if (newHead == nullptr)
			{
				newHead = new ListNode(l2->val);
				ptr = newHead;
				l2 = l2->next;
				continue;
			}

			ListNode *node = new ListNode(l2->val);
			ptr->next = node;
			ptr = node;
			l2 = l2->next;
		}

		return newHead;
    }
};

int main()
{

	return 0;
}