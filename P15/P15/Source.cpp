#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

	Note: The solution set must not contain duplicate triplets.

	For example, given array S = [-1, 0, 1, 2, -1, -4],

	A solution set is:
	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> solution;
		sort(begin(nums), end(nums));

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums.at(i) > 0)
				break;

			if (i > 0 && nums.at(i) == nums.at(i-1))
				continue;

			int result = 0 - nums.at(i);
			int j = i + 1, k = nums.size() - 1;
			while (j < k && j < nums.size())
			{
				if (nums.at(j) + nums.at(k) == result)
				{
					int tmp[] = {nums.at(i), nums.at(j), nums.at(k)};
					solution.push_back(vector<int>(begin(tmp), end(tmp)));

					while (j+1 < nums.size() && nums.at(j+1) == nums.at(j)) j++;
					while (k -1 >= 0 && nums.at(k-1) == nums.at(k)) k--;

					j++, k--;
				}
				else if (nums.at(j) + nums.at(k) < result)	j++;
				else k--;
			}
		}

		return solution;
    }
	//vector<vector<int>> threeSum(vector<int>& nums) {
 //       vector<vector<int>> res;
 //       sort(nums.begin(), nums.end());
 //       for (int k = 0; k < nums.size(); ++k) {
 //           if (nums[k] > 0) break;
 //           if (k > 0 && nums[k] == nums[k - 1]) continue;
 //           int target = 0 - nums[k];
 //           int i = k + 1, j = nums.size() - 1;
 //           while (i < j) {
 //               if (nums[i] + nums[j] == target) {
	//				int tmp[] = {nums[k], nums[i], nums[j]};
 //                   res.push_back(vector<int>(begin(tmp), end(tmp)));
 //                   while (i < j && nums[i] == nums[i + 1]) ++i;
 //                   while (i < j && nums[j] == nums[j - 1]) --j;
 //                   ++i; --j;
 //               } else if (nums[i] + nums[j] < target) ++i;
 //               else --j;
 //           }
 //       }
 //       return res;
 //   }


};

int main()
{
	Solution solution;
	int a[] = {-2,-1,-1,0,2};

	vector<vector<int>> test = solution.threeSum(vector<int>(begin(a), end(a)));
	for (auto vec: test)
	{
		for (auto e: vec)
			cout << e << " ";
		cout << endl;
	}
	return 0;
}
