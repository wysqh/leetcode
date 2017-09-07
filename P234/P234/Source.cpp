#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
		ListNode* ptr = head;
		int tol = 0;
		while (ptr != nullptr)
		{
			++tol;
			ptr = ptr->next;
		}

		vector<int> nums(tol);
		int index = 0;
		ptr = head;
		
		while (ptr != nullptr)
		{
			nums[index++] = ptr->val;
			ptr = ptr->next;
		}

		for (int i = 0, j = nums.size() - 1; i < j; ++i, --j)
			if (nums[i] != nums[j])
				return false;
		
		return true;
    }
};