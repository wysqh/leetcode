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
    int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return max(calculatePath(root->left)+calculatePath(root->right),
			max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

	int calculatePath(TreeNode* node)
	{
		if (node == nullptr)
			return 0;

		return max(1+calculatePath(node->left), 1+calculatePath(node->right));
	}
};
