#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//59.98%

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		ListNode* left, *right = nullptr;
		TreeNode* node = new TreeNode(split(head, left, right));
		node->left = sortedListToBST(left);
		node->right = sortedListToBST(right);

		return node;
    }

	int length(ListNode* head)
	{
		int length = 0;
		while (head != nullptr)
		{
			++length;
			head = head->next;
		}

		return length;
	}

	int split(ListNode*head, ListNode* &left, ListNode* &right)
	{
		if (head == nullptr)
		{
			left = nullptr;
			right = nullptr;
			return 0;
		}

		int index = 0;
		int mid = (length(head) - 1) / 2;
		int rtValue;
		ListNode* ptr = head;
		
		left = head;
		while (ptr != nullptr)
		{
			if (index == mid)
			{
				if (mid == 0)
					left = nullptr;
				right = ptr->next;
				ptr->next = nullptr;
				rtValue = ptr->val;
			}

			++index;
			ptr = ptr->next;
		}

		return rtValue;
	}
};

int main()
{

}