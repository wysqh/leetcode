#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		unordered_map<int, int> res;
		vector<int> ans(findNums.size());
		for (int i = 0; i < nums.size(); i++)
			res[nums[i]] = i;

		for (int seq = 0; seq < findNums.size(); ++seq)
		{
			auto it = res.find(findNums[seq]);
			
			bool bFind = false;
			for (int i = it->second + 1; i < nums.size(); ++i)
			{
				if (nums[i] > it->first)
				{
					bFind = true;
					ans[seq] = nums[i];
					break;
				}
			}
			if (!bFind)
				ans[seq] = -1;	
		}

		return ans;
    }
};