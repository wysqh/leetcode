#include <iostream>
#include <vector>
#include <deque>
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
    vector<int> largestValues(TreeNode* root) {
		deque<TreeNode*> vals, backups;
		vector<int> rt;

		if (root == nullptr)
			return rt;

		vals.push_back(root);
		while (!vals.empty())
		{
			int maxval = INT_MIN;
			while (!vals.empty())
			{
				TreeNode* node = vals.front();
				vals.pop_front();
				maxval = max(maxval, node->val);
				if (node->left != nullptr)
					backups.push_back(node->left);
				if (node->right != nullptr)
					backups.push_back(node->right);
			}
			vals = backups;
			backups.clear();
			rt.push_back(maxval);
		}

		return rt;
    }
};