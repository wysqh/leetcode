#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* t) {
        string res = "";

		if (t == nullptr)
			return res;

		traversal(t, res);
		return res;
    }

	void traversal(TreeNode* node, string& res)
	{
		if (node == nullptr)
			return;
		res += to_string(node->val);

		if (node->left == nullptr && node->right == nullptr)
			return;
		else if(node->left != nullptr)
		{
			res += "(";
			traversal(node->left, res);
			res += ")";
			if (node->right != nullptr)
			{
				res += "(";
				traversal(node->right, res);
				res += ")";
			}
		}
		else
		{
			res += "(";
			traversal(node->left, res);
			res += ")(";
			traversal(node->right, res);
			res += ")";
		}

	}
};