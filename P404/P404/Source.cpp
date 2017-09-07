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
    int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
			return 0;
		else if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
			return root->left->val + sumOfLeftLeaves(root->right);
		else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};