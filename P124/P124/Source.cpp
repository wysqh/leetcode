#include <iostream>
using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define MAX(a,b,c)	(a >= b) ? ((a >= c) ? a : c) : (b>=c) ? b : c


class Solution {
public:
    int maxPathSum(TreeNode*& root) {
		if (root == nullptr)
			return INT_MIN;

		int sum = root->val + max(findMaxPath(root->left), 0) + max(findMaxPath(root->right), 0);
		return MAX(sum, maxPathSum(root->left), maxPathSum(root->right));

    }
	
	int findMaxPath(TreeNode*& node)
	{
	    if (node == nullptr)
	        return 0;
	    
	    return MAX(node->val + findMaxPath(node->left), node->val + findMaxPath(node->right), node->val);
	}
	
};

int main()
{
	int a = MAX(5,4,4.5);
	cout <<  a  << endl;
}