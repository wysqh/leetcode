#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxN = INT_MIN;
		int sumN = 0;
		for (int i = 0; i < k; i++)
			sumN += nums[i];
		maxN = max(maxN, sumN);
		for (int i = 1; i <= nums.size() - k; i++)
		{
			sumN = sumN - nums[i-1] + nums[i+k-1];
			maxN = max(maxN, sumN);
		}
		return (double)maxN / k;
    }
};