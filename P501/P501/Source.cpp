#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
		unordered_map<int, int> count;
		
		travel(root, res);
		for (const auto&r : res)
			++count[r];

		auto bound = max_element(begin(count), end(count), [](const pair<int,int> p1, const pair<int, int> p2)->bool{
			return p1.second < p2.second;
		});
		res.clear();

		for (const auto& e: count)
			if (e.second == bound->second)
				res.push_back(e.first);

		return res;
    }

	void travel(TreeNode* node, vector<int>& vec)
	{
		if (node == nullptr)
			return;

		vec.push_back(node->val);
		travel(node->left, vec);
		travel(node->right, vec);
	}
};