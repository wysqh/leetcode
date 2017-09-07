#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//83.59%

class Solution {
public:
    int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr)
			return minDepth(root->right) + 1;
		if (root->right == nullptr)
			return minDepth(root->left) + 1;

		return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
    }
};