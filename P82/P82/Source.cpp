#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//66.05%

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
				    if (ptr == nullptr)
				        return nullptr;
					link = ptr;
				}
				else
				{
					ListNode* tmp = link;
					while (tmp != nullptr && tmp->next != nullptr)
					{
						if (tmp->next == p)
						{
							break;
						}
						
						tmp = tmp->next;
					}
					tmp->next = ptr;
				}
			}
		}
		return link;

    }
};