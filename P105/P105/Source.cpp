#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//8.02%

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.empty() || inorder.empty())
			return nullptr;

		int val = postorder.at(postorder.size() - 1);
		vector<int>::iterator it = find(begin(inorder), end(inorder), val);

		vector<int> leftInoreder(inorder.begin(), it);  
		vector<int> rightInorder(it+1, inorder.end());
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInoreder.size());
		vector<int> rightPostorder(postorder.begin() + leftInoreder.size(), postorder.begin() + leftInoreder.size() + rightInorder.size());
		
		TreeNode *child = new TreeNode(val);
		child->left = buildTree(leftInoreder, leftPostorder);
		child->right = buildTree(rightInorder, rightPostorder);
		return child;
    }

	void traversal(TreeNode* root)
	{
		if (root == nullptr)
			return;

		traversal(root->left);
		cout << root->val << " ";
		traversal(root->right);
	}
};

int main()
{
	Solution s;
	int a[] = {3,2,1,5,4,6};
	int b[] = {3,2,5,6,4,1};
	vector<int> inorder(begin(a), end(a));
	vector<int> postorder(begin(b), end(b));

	s.traversal(s.buildTree(inorder, postorder));
}