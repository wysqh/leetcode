#include <iostream>
using namespace std;
struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findTilt(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return abs(addSum(root->left)-addSum(root->right))+findTilt(root->left)
			+findTilt(root->right);
    }

	int addSum(TreeNode* node)
	{
		if (node == nullptr)
			return 0;

		return node->val + addSum(node->left) + addSum(node->right);
	}
};