#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
	unordered_map<int, bool> dp;
	vector<bool> used;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int sum = (1+maxChoosableInteger) * maxChoosableInteger /2;
		if (sum < desiredTotal) return false;
		if (desiredTotal <= 0) return true;

		used.resize(maxChoosableInteger+1, false);
		return helper(desiredTotal);
    }

	bool helper(int desired)
	{
		if (desired <= 0) return false;
		int key = format(used);
		if (dp.find(key) != dp.end())
			return dp.at(key);

		for (int i = 1; i < used.size(); ++i)
		{
			if (!used[i])
			{
				used[i] = true;
				if (!helper(desired-i))
				{
					pair<int, bool> tmp = make_pair(key, true);
					used[i] = false;
					return true;
				}
				used[i] = false;
			}
		}
		dp.insert(pair<int, bool>(key, false));
		return false;
	}

	int format(vector<bool> used)
	{
		int num = 0;
		for (const auto& e: used)
		{
			num <<= 1;
			if (e) num |= 1;
		}

		return num;
	}
};
