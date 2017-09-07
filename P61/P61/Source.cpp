#include <iostream>
#include <string>
#include <vector>

using namespace std;

//22.04%

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
		ListNode *ptr = head, *p = nullptr, *node = head;
		while (node != nullptr)
		{
			length++;
			node = node->next;
		}

		node = head;
		while (node->next != nullptr)
			node = node->next;
		node->next = head;

		while (length++ < length- k)
		{
			p = ptr;
			ptr = ptr->next;
		}
		p->next = nullptr;

		return ptr;
    }
};

int main()
{

	return 0;
}