#include <iostream>
#include <vector>
using namespace std;

//74.24%

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
			return true;

		if (p->val != q->val || (p == nullptr && q != nullptr) || p != nullptr && q == nullptr)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};