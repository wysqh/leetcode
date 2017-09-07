#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
		unordered_map<int, int> res;
		travel(root, res);

		for (const auto& r :res)
			if (res.find(k-r.first) != res.end() && k != 2 * r.first)
				return true;

		return false;
    }

	void travel(TreeNode* node, unordered_map<int, int>& res)
	{
		if (node == nullptr)
			return;

		res[node->val] = node->val;
		travel(node->left, res);
		travel(node->right, res);

		return;
	}
};