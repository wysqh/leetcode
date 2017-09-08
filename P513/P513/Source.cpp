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
    int findBottomLeftValue(TreeNode* root) {
		deque<TreeNode*> cur, backups;
		int val = -1;
		cur.push_back(root);
		while (!cur.empty())
		{
			val = cur.front()->val;
			while (!cur.empty())
			{
				auto node = cur.front();
				cur.pop_front();
				if (node->left != nullptr)
					backups.push_back(node->left);
				if (node->right != nullptr)
					backups.push_back(node->right);
			}
			if (backups.empty())
				break;
		
			cur = backups;
			backups.clear();
		}
		return val;
	}
};