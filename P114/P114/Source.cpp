#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* cur = root;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right = right;
        flatten(root->left);
        flatten(root->right);
    }
};