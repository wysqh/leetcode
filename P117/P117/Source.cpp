#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

 struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
	  int val;

	  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

 //4.15%

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root == nullptr)
			return;

		deque<TreeLinkNode*> curQueue;
		deque<TreeLinkNode*> nxtQueue;

		curQueue.push_back(root);
		while (!curQueue.empty())
		{
			deque<TreeLinkNode*> cpy = curQueue;
			while (!curQueue.empty())
			{
				TreeLinkNode* link = curQueue.front();
				curQueue.pop_front();
				if (link->left != nullptr)
					nxtQueue.push_back(link->left);
				if (link->right != nullptr)
					nxtQueue.push_back(link->right);
			}

			TreeLinkNode* link = cpy.front();
			cpy.pop_front();
			while (!cpy.empty())
			{
				TreeLinkNode* nxt = cpy.front();
				cpy.pop_front();
				link->next = nxt;
				link = nxt;
			}
			link->next = nullptr;

			curQueue = nxtQueue;
			nxtQueue.clear();
		}
    }
};