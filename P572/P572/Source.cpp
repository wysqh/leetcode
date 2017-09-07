#include <iostream>
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
		bool l, r;
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr)
			return false;
		
		return checksameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

	bool checksameTree(TreeNode* t1, TreeNode* t2)
	{
		if (t1 == nullptr && t2 == nullptr)
			return true;
		if (t1 == nullptr || t2 == nullptr)
			return false;

		return (t1->val == t2->val) ? (checksameTree(t1->left, t2->left)&& 
			checksameTree(t1->right, t2->right)) : false;
	}
};

int main()
{
	int* a = new int;
	int* b = nullptr;
	cout << (0&&1 ) << endl;
}