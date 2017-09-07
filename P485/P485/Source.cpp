#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxN = 0;
		int sumN = 0;

		for (const auto& e: nums)
		{
			if (e == 0) {
				maxN = max(maxN, sumN);
				sumN = 0;
			} else {
				sumN++;
			}
		}

		return max(maxN, sumN);
    }
};