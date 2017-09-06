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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> rtValue;
		vector<int> number;
		for (int i = 1; i <=n; ++i)
			number.push_back(i);

		for (int i = 1; i <= n; ++i)
		{
			TreeNode* head = new TreeNode(i);	
			vector<int> tmp = number;
			tmp.erase(tmp.begin() + i - 1);
			generate(rtValue, head, tmp);
		}

		return rtValue;
    }

	void generate(vector<TreeNode*>& rtValue, TreeNode* head, vector<int>& number)
	{
		if (!number.size())
		{
			TreeNode* cpy = makeCpy(nullptr, head);
			if (rtValue.size() == 0)
				rtValue.push_back(cpy);
			else
			{
				for (auto e: rtValue)
					if (compare(cpy, e))
						return;

				rtValue.push_back(cpy);
			}
			return;
		}

		for (int i = 0; i < number.size(); ++i)
		{
			TreeNode* cur = new TreeNode(number[i]);
			TreeNode* parent = search(head, nullptr, cur->val);
			if (parent->val > cur->val)
				parent->left = cur;
			else parent->right = cur;

			vector<int> tmp = number;
			tmp.erase(tmp.begin() + i);
			generate(rtValue, head, tmp);
			if (parent->val > cur->val)
				parent->left = nullptr;
			else parent->right = nullptr;
			delete cur;
		}

		return ;
	}

	TreeNode* search(TreeNode* head, TreeNode* ptr, int val)
	{
		TreeNode* list = nullptr;
		if (head == nullptr)
		{
			return ptr;
		}
		
		ptr = head;
		if (head->val > val)
			list = search(head->left, ptr, val);
		else if (head->val < val)
			list = search(head->right, ptr, val);

		return list;
	}

	TreeNode* makeCpy(TreeNode* head, TreeNode* node)
	{
		if (node == nullptr)
			return nullptr;

		if (head == nullptr)
		{
			head = new TreeNode(node->val);
			head->left = makeCpy(head, node->left);
			head->right = makeCpy(head, node->right);
		}
		else
		{
			TreeNode* ptr = new TreeNode(node->val);
			ptr->left = makeCpy(head, node->left);
			ptr->right = makeCpy(head, node->right);
			return ptr;
		}

		return head;
	}

	bool compare(TreeNode* l, TreeNode* r)
	{
		bool bF = true;
		if ((l == nullptr && r != nullptr) || (l != nullptr && r == nullptr))
			return false;
		if (l == nullptr && r == nullptr)
			return true;

		if (l->val == r->val)
		{
			if (bF)
				bF = compare(l->left, r->left);
			if (bF)
				bF = compare(l->right, r->right);
		}
		else return false;

		return bF;
	}
};

int main()
{
	Solution s;
	s.generateTrees(3);
}