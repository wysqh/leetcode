#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		unordered_map<int, int> cur;
		for (const auto& e: nums)
			if(cur.find(e) == cur.end())
				cur.insert(pair<int, int>(e, e));

		vector<int> ans;
		for (int i = 1; i <= nums.size(); i++)
			if (cur.count(i) == 0 )
				ans.push_back(i);

		return ans;
    }
};