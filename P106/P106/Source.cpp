#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <map>
using namespace std;

//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its level order traversal as:

//28.54%

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<pair<int, int>> output;
		traversal(output, root, 0);

		int depth = maxDepth(root);
		vector<vector<int>> rtValue(depth);
		for (auto e: output)
			rtValue[depth - 1 - e.first].push_back(e.second);

		return rtValue;			
    }

	void traversal(vector<pair<int, int>> &o, TreeNode* node, int level)
	{
		if (node == nullptr)
			return;

		traversal(o, node->left, level + 1);
		o.push_back(pair<int, int>(level, node->val));
		traversal(o, node->right, level + 1);
	}

	int maxDepth(TreeNode *node)
	{
		if (node == nullptr)
			return 0;

		return max(maxDepth(node->left) + 1, maxDepth(node->right) + 1);
	}
};

int main()
{
	return 0;
}