#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	Solution operator < (const Solution& s)
	{
	}
    int getMoneyAmount(int n) {
        vector<vector<int>> vec(n+1, vector<int>(n+1, 0));
		return findMinCost(1, n, vec);
    }

	int findMinCost(int l, int r, vector<vector<int>>& vec) {
		int rtValue = 0;

		if (r - l <= 0)
			rtValue = 0;
		else if (r - l == 1)
			rtValue = l;
		else if (r-l == 2)
			rtValue = (l+r)/2;
		else if (vec[l][r] != 0)
		    rtValue = vec[l][r];
		else
		{
			int minCost = INT_MAX;
			for (int i = l+1; i <= r-1; i++){
				int cost = i + max(findMinCost(l, i - 1, vec),  findMinCost(i + 1,r, vec));
				minCost = minCost <= cost ? minCost : cost;
			}
			rtValue = minCost;
			vec[l][r] = minCost;
		}
		
		return rtValue;
	}
};


int main()
{
	Solution s;
	cout << s.getMoneyAmount(7) << endl;
	return 0;
}

//1 2 3 4 5 6 7