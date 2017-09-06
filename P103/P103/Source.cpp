#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int v): val(v), left(nullptr), right(nullptr)
	{
	}
};

//4.65%

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<pair<int, int>> output;
		traversal(output, root, 0);

		int depth = maxDepth(root);
		vector<vector<int>> rtValue(depth);
		for (auto e: output)
			rtValue[e.first].push_back(e.second);

		for (int i = 0; i < depth; ++i)
			if (i % 2 != 0)
				reverse(begin(rtValue[i]), end(rtValue[i]));

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