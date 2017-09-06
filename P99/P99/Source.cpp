#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//33.96%

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> unorderedType, ordered, recover;
		traversal(root, unorderedType);
	
		ordered = unorderedType;
		sort(begin(ordered), end(ordered));
		for (int i = 0; i < ordered.size(); ++i)
			if (ordered[i] - unorderedType[i] != 0)
				recover.push_back(ordered[i]);

		recovers(root, recover);
    }

	void traversal(TreeNode* node, vector<int>& vals)
	{
		if (node == nullptr)
			return;

		traversal(node->left, vals);
		vals.push_back(node->val);
		traversal(node->right, vals);
	}

	void recovers(TreeNode* node, vector<int>& vals)
	{
		if (node == nullptr)
			return;

		recovers(node->left, vals);
		if (contains(node->val, vals))
			recover(node, vals);
		recovers(node->right, vals);
	}

	bool contains(int keys, vector<int> vals)
	{
		for (auto val: vals)
			if (val == keys)
				return true;

		return false;
	}

	void recover(TreeNode*& node, vector<int>& vals)
	{
		int index = node->val == vals[0] ? 0 : 1;

		node->val = vals[index];
		vals.erase(vals.begin() + index);
	}
};