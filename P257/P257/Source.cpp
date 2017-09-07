#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string strs = "";
		vector<string> sv;
		if (root == nullptr)
			return sv;

		printTrack(root, sv, strs);
		return sv;
    }

	void printTrack(TreeNode* node, vector<string>& sv, string str)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			str += to_string(node->val);
			sv.push_back(str);
			return;
		}
		else if (node->right == nullptr)	
			printTrack(node->left, sv, str+to_string(node->val)+"->");
		else if (node->left == nullptr)
			printTrack(node->right, sv, str+to_string(node->val)+"->");
		else
		{
			printTrack(node->left, sv, str+to_string(node->val)+"->");
			printTrack(node->right, sv, str+to_string(node->val)+"->");
		}
	}
};

int main()
{
	
}