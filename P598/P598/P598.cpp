#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
		if (ops.empty())
			return m*n;

		int x = INT_MAX, y = INT_MAX;
		for (const auto& op : ops)
		{
			x = min(x, min(op[0], m));
			y = min(y, min(op[1], n));
		}

		return x * y;
    }
};

