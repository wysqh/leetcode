#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> backup(begin(nums), end(nums));
		sort(begin(nums), end(nums));
		vector<int> diff;
		for(int i = 0; i < nums.size(); i++)
			diff.push_back(nums[i] - backup[i]);
		int pre = 0;
		for (int i = 0; i < diff.size(); i++)
			if (diff[i] == 0) pre++;
			else break;
		for (int i = diff.size() - 1; i >= 0; i--)
			if (diff[i] == 0) pre++;
			else break;

			return diff.size() - pre > 0 ? diff.size() - pre : 0;
    }
};

int main()
{
	return 0;
}