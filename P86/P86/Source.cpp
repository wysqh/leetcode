#include <iostream>
#include <string>
#include <vector>

using namespace std;

//【解析】
//题意：给定一个单链表和一个x，把链表中小于x的放到前面，大于等于x的放到后面，每部分元素的原始相对位置不变。
//
//思路：其实很简单，遍历一遍链表，把小于x的都挂到head1后，把大于等于x的都放到head2后，最后再把大于等于的链表挂到小于链表的后面就可以了。
//
//这道题不难，主要是给不熟悉指针的同学学习交流。

//26.83%

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* head1 = nullptr;
		ListNode* head2 = nullptr;
		ListNode* rtValue = nullptr;

		ListNode* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->val < x)
			{
				if (head1 == nullptr)
				{
					head1 = new ListNode(ptr->val);
				}
				else
				{
					ListNode* node = new ListNode(ptr->val);
					ListNode* link = head1;
					while (link->next != nullptr)
						link = link->next;
					link->next = node;
				}
			}
			else
			{
				if (head2 == nullptr)
				{
					head2 = new ListNode(ptr->val);
				}
				else
				{
					ListNode* node = new ListNode(ptr->val);
					ListNode* link = head2;
					while (link->next != nullptr)
						link = link->next;
					link->next = node;
				}
			}

			ptr = ptr->next;
		}

		ListNode *link = head;
		while (link != nullptr)
		{
			ListNode* tmp = link;
			link = link->next;

			delete tmp;
		}

		ListNode *linkage = head1;
		while (linkage && linkage->next != nullptr)
		{
			linkage = linkage->next;
		}
		if (linkage == nullptr)
			rtValue = head2;
		else
		{
			linkage->next = head2;
			rtValue = head1;
		}

		return rtValue;
	}
};