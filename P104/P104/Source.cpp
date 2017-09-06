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

//13.49%

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		int val = preorder.at(0);
		vector<int>::iterator it = find(begin(inorder), end(inorder), val);

		vector<int> leftInoreder(inorder.begin(), it);  
		vector<int> rightInorder(it+1, inorder.end());
		vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInoreder.size() + 1);
		vector<int> rightPreorder(preorder.begin() + leftInoreder.size() + 1, preorder.begin() + leftInoreder.size() + rightInorder.size() + 1);
		
		TreeNode *child = new TreeNode(val);
		child->left = buildTree(leftPreorder, leftInoreder);
		child->right = buildTree(rightPreorder, rightInorder);
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
	int a[] = {1,2,3,4,5,6};
	int b[] = {3,2,1,5,4,6};
	vector<int> p(begin(a), end(a));
	vector<int> i(begin(b), end(b));

	s.traversal(s.buildTree(p, i));
}