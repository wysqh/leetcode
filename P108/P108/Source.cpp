#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//39.64%

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
			return nullptr;

		int mid = (nums.size() - 1) / 2;
		vector<int> left(begin(nums), begin(nums) + mid);
		vector<int> right(begin(nums) + mid + 1, end(nums));

		TreeNode *node = new TreeNode(nums[mid]);
		node->left = sortedArrayToBST(left);
		node->right = sortedArrayToBST(right);

		return node;
    }
};