#include <string>
#include <vector>
using namespace std;

typedef bool (*fptr)(int, int);

//41.56%

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare1(int a, int b)
{
	return a < b;
}

bool compare2(int a, int b)
{
	return a > b;
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
		vector<int> vals;
		travsal(root, vals);

		if (vals.empty())
			return true;

		for (int i = 0; i < vals.size() - 1; ++i)
			if (vals[i] >= vals[i+1])
				return false;

		return true;
    }

	void travsal(TreeNode* node, vector<int>& vals)
	{
		if (node == nullptr)
			return;

		travsal(node->left, vals);
		vals.push_back(node->val);
		travsal(node->right, vals);
	}
};