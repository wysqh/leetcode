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

//16.27%

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
		treeDFS(nums, root, 0);
		
		int sum = 0;
		for_each(nums.begin(), nums.end(), [&sum](int item){sum += item;});
		return sum;
    }

	void treeDFS(vector<int>& nums, TreeNode* node, int num)
	{
		if (node == nullptr)
		{
			nums.push_back(num);
			return;
		}

		treeDFS(nums, node->left, num * 10 + node->val);
		treeDFS(nums, node->right, num * 10 + node->val);
	}
};

