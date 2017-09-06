#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//74.72%

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(begin(candidates), end(candidates));
		vector<vector<int>> rtValue;
		vector<int> container;
		findAnswer(candidates, target, 0, container, rtValue);

		return rtValue;
    }

	void findAnswer(vector<int> candidates, int target, int start, vector<int> container,  vector<vector<int>>& rtValue)
	{
		if (target == 0)
		{
			rtValue.push_back(container);
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