#include <iostream>
#include <unordered_map>
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
	unordered_map<TreeNode*, bool> node2vals;
    int rob(TreeNode* root) {
		if (root == nullptr)
			return 0;
		else if (root->left == nullptr && root->right == nullptr)
			return root->val;
		else if (root->left == nullptr)
			return max(root->val + rob(root->right->left) + rob(root->right->right),
			rob(root->right));
		else if (root->right == nullptr)
			return max(root->val + rob(root->left->left) + rob(root->left->right),
			rob(root->left));
		else return max(root->val + rob(root->left->left) + rob(root->left->right)
			+ rob(root->right->left) + rob(root->right->right), rob(root->left) + 
			rob(root->right));
    }
};