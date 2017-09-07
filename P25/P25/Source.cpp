#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

	k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

	You may not alter the values in the nodes, only nodes itself may be changed.

	Only constant memory is allowed.

	For example,
	Given this linked list: 1->2->3->4->5

	For k = 2, you should return: 2->1->4->3->5

	For k = 3, you should return: 3->2->1->4->5
*/

//学习一样链表的反转

//87.03%
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0, index = 0, frag = 0;
		ListNode* ptr = head, *p = nullptr, *newHead = nullptr;
		if (head == nullptr)
			return head;

		while (ptr != nullptr)
		{
			length = length + 1;
			ptr = ptr->next;
		}
		if ( k > length)
			return head;

		while (frag++ < length / k)
		{
			if (newHead == nullptr)
			{
				newHead = reverse(head, k);
				p = getHead(newHead, k);
			}
			else
			{
				ListNode *node = reverse(p->next, k);
				p->next = node;
				p = getHead(node, k);
			}
		}
		
		return newHead;
    }

	ListNode* reverse(ListNode* head, int k)
	{
		ListNode *p1,*p2,*p3;  
		int i = 0;
		if(head==NULL || k ==1)  
			return head;  
		p1=head;  
		p2=p1->next;  
		while(p2 && i < k - 1)             //注意条件  
		{  
			p3=p2->next;       //要改变p2->next的指针，所以必须先保留p2->next           
			p2->next=p1;  
			p1=p2;            //循环往后  
			p2=p3;  
			i++;
		}  

		head->next=p3;   //原先的head已经变成tail，别忘了置空，只有到这步才能置空  
		head=p1;  

		return head;  
	}

	ListNode* getHead(ListNode* node, int k)
	{
		int i = 0;
		while (node != nullptr && i < k - 1)
		{
			node = node->next;
			i++;
		}

		return node;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* n1 = new ListNode(2);
	//ListNode* n2 = new ListNode(3);
	//ListNode *n3 = new ListNode(4);
	head->next = n1;
	n1->next = nullptr;
	//n2->next = n3;
	//n3->next = nullptr;

	Solution solution;
	head = solution.reverseKGroup(head, 3);
	while (head)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}