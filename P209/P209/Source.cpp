#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) { 
            sum += nums[i]; 
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
/*
	A Solution that will cause MLE.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
		for (int len = 1; len <= nums.size(); len++)
			for (int i = 0; i + len <= nums.size(); i++)
			{
				int j = i + len - 1;
				if (j == i)
					dp[i][j] = nums[i];
				else if(j - i == 1)
					dp[i][j] = dp[i+1][j] + nums[i];
				else dp[i][j] = dp[i+1][j-1] + nums[i] + nums[j];
			}
		int minN = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < nums.size(); j++)
				if (dp[i][j] >= s)
					minN = min(minN, j-i+1);

		return minN == INT_MAX ? 0 : minN;
	}
};