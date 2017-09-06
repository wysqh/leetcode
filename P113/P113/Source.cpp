#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//78.02%
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> rtValue;
		vector<int> container;

		generate(rtValue, container, root, sum);

		return rtValue;
    }

	void generate(vector<vector<int>> &rtValue, vector<int>& container, TreeNode* node, int sum)
	{
		if (node == nullptr)
			return;

		if (node->left == nullptr && node->right == nullptr && sum - node->val == 0)
		{
			container.push_back(node->val);
			rtValue.push_back(container);
			container.pop_back();
			return;
		}

		container.push_back(node->val);
		generate(rtValue, container, node->left, sum - node->val);
		generate(rtValue, container, node->right, sum - node->val);
		container.pop_back();

		return;
	}
};