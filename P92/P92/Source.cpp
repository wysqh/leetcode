#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//19.33%

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index = 1;
		ListNode* ptr = head, *pr = nullptr, *hd = nullptr;

		while (index < m)
		{
			pr = ptr;
			ptr = ptr->next;
			index = index + 1;
		}

		hd = ptr;
		ListNode* nxt = nullptr, *link = ptr->next;
		while (index < n)
		{
			nxt = link;
			link = nxt->next;
			nxt->next = ptr;
			ptr = nxt;
			index = index + 1;
		}
		
		if (m == 1 && n > m)
	    {
	        head->next = link;
	        return nxt;
	    }
	    if (n == m)
	        return head;

		pr->next = nxt;
		hd->next = link;

		return head;
    }
};