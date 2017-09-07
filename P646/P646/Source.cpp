#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortMethod(const vector<int>& a,const vector<int> & b)
{
	return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		if (pairs.empty())
			return 0;
		
		sort(begin(pairs), end(pairs), sortMethod);
		int num = 0;

		int maxPostOrder = pairs[0][1];
		for (int i = 1; i < pairs.size(); ++i)
		{
			if (pairs[i][0] > maxPostOrder)
			{
				num++;
				maxPostOrder = pairs[i][1];
			}
		}

		return num+1;
    }
};

int main()
{
	int a[] = {1,2};
	int b[] = {2, 1};
	vector<vector<int>> pairs;
	vector<int> a1(begin(a), end(a));
	vector<int> b1(begin(b), end(b));
	pairs.push_back(a1);
	pairs.push_back(b1);
	Solution s;
	s.findLongestChain(pairs);
	return 0;
}
