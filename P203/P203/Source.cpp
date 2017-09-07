#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
   ListNode* removeElements(ListNode* head, int val) {
		ListNode* node = head;
		vector<int> res;

		while(node != nullptr)
		{
			if (node->val != val)
				res.push_back(node->val);
		
			node = node->next;
		}

		node = head;
		int index = 0;
		while (index < res.size())
		{
			node->val = res[index++];
			node = node->next;
		}
		
		ListNode* tmp = node;
		node = nullptr;

		while (tmp != nullptr)
		{
			ListNode* gc = tmp;
			tmp = tmp->next;
			delete gc;
		}

		return head;
	}
}; 

