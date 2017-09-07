#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//32.03%

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(begin(candidates), end(candidates));
		set<vector<int>> rtValue;
		vector<int> container;
		findAnswer(candidates, target, 0, container, rtValue);

		return vector<vector<int>>(begin(rtValue), end(rtValue));
    }

	void findAnswer(vector<int> candidates, int target, int start, vector<int> container,  set<vector<int>>& rtValue)
	{
		if (target == 0)
		{
			rtValue.insert(container);
			return;
		}

		for (int i = start; i < candidates.size(); i++)
		{
			if (target - candidates.at(i) < 0)
				break;

			container.push_back(candidates.at(i));
			findAnswer(candidates, target - candidates.at(i), i + 1, container, rtValue);
			container.pop_back();
		}
	}
};

int main()
{

	return 0;
}