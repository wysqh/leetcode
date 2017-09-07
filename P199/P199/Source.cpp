#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)
			return vector<int>();

		vector<int> left = rightSideView(root->left);
		vector<int> right = rightSideView(root->right);
		
		if (left.size() >= right.size())
		{
			vector<int> res(left.size() + 1);
			res[0] = root->val;
			std::copy(right.begin(), right.end(), left.begin());
			std::copy(left.begin(), left.end(), res.begin()+1);
			return res;
		}
		vector<int> res(right.size()+1);
		res[0] = root->val;
		std::copy(right.begin(), right.end(), res.begin()+1);
		return res;
    }
};