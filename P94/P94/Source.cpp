#include <iostream>
#include <vector>
#include <string>

using namespace std;

//2.89%

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rtValue;
		traversal(root, rtValue);
		
		return rtValue;
    }

	void traversal(TreeNode *node, vector<int> &rtValue)
	{
		if (node == nullptr)
			return;

		traversal(node->left, rtValue);
		rtValue.push_back(node->val);
		traversal(node->right, rtValue);

		return;
	}

};