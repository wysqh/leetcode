#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

// 思路:MergeKlists就是MergeTwo的拓展,可以看作不断的合并两个数组的过程,直至数组中只剩一个列表

//37.73%

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {			     
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;

		while (lists.size() != 1)
		{
			lists.push_back(mergeTwoLists(lists.at(0), lists.at(1)));
			lists.erase(begin(lists));
			lists.erase(begin(lists));
		}

		return lists.at(0);
    }

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