#include <iostream>
#include <vector>
#include <deque>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
		deque<TreeNode*> res;
		deque<TreeNode*> backup;
		vector<double> aver;
		res.push_back(root);
		while (!res.empty())
		{
			double sum  = 0, tol = 0;
			while (!res.empty())
			{
				TreeNode* node = res.front();
				res.pop_front();

				sum += node->val;
				++tol;
				if (node->left != nullptr)	backup.push_back(node->left);
				if (node->right != nullptr) backup.push_back(node->right);
			}
			aver.push_back(sum/tol);
			res = backup;
			backup.clear();
		}

		return aver;
    }
};