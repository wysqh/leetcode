#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//29.07%
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return false;
		if (!root->left && !root->right && sum - root->val == 0)
		    return true;

		if (root->left == nullptr)
			return hasPathSum(root->right, sum - root->val);
		else if (root->right == nullptr)
			return hasPathSum(root->left, sum - root->val);

		bool left = hasPathSum(root->left, sum - root->val);
		bool right = hasPathSum(root->right, sum-root->val);

		return left || right;
    }
};