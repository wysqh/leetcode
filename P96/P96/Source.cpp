#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//35.25%

class Solution {
public:
    int numTrees(int n) {
		vector<int> G(n+1);
		G[0] = G[1] = 1;
    
		for(int i=2; i<=n; ++i) {
    		for(int j=1; j<=i; ++j) {
    			G[i] += G[j-1] * G[i-j];
    		}
		}

		return G[n];
    }
};

int main()
{
	Solution s;
	cout << s.numTrees(3) << endl;

	return 0;
}