#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Total Accepted: 147765
	Total Submissions: 395889
	Difficulty: Medium
	Contributors: Admin
	Given a linked list, swap every two adjacent nodes and return its head.

	For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.

	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

//2.05%

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		ListNode *ptr = head;
		int i = 0;
		while (ptr != nullptr)
		{
			if ((i++) % 2  == 0 && ptr->next != nullptr)
			{
				int tmp = ptr->next->val;
				ptr->next->val = ptr->val;
				ptr->val = tmp;
			}
			ptr = ptr->next;;
		}

		return head;
    }
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(3);
	head->next = n1;
	n1->next = n2;

	Solution solution;
	ListNode *test = solution.swapPairs(head);

	return 0;
}