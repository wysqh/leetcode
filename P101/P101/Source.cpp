#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//36.02%
//
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		return traversal(root->left, root->right);
    }

	bool traversal(TreeNode* p, TreeNode* q)
	{
		if (p == nullptr && q == nullptr)
			return true;

		if (p == nullptr && q != nullptr || p != nullptr && q == nullptr || p->val != q->val)
			return false;

		return traversal(p->left, q->right) && traversal(p->right, q->left);
	}
};

int main()
{
	vector<int> dp(10, 1);
	int sun = 0;
	for_each(dp.begin(), dp.end(), [&](int i){sun+=i;});
	return 0;
}