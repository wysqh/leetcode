#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode* ptr = head, *link = head, *p = nullptr;
		while (ptr && ptr->next != nullptr)
		{
			p = ptr;
			ptr = ptr->next;
			while (ptr && ptr->val == p->val)
			{
				ptr = ptr->next;
			}
				
			if (p->next == ptr)
			{
				continue;
			}
			else
			{
				if (link == p)
				{
					link->next = ptr;
				}
				else
				{
					p->next = ptr;
				}
			}
		}
		return link;

    }
};