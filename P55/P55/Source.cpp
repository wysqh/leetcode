#include <iostream>
#include <string>
#include <vector>

using namespace std;

//4.86%

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cPos = 0, fPos = 0;
		int n = nums.size() - 1;
		int i = 0;
		
		while (cPos < n)
		{
			fPos = (fPos > i + nums[i]) ? fPos : i + nums[i];
			if (i == cPos)
			{
				if (i != 0 && cPos == fPos)
					return false;
				cPos = fPos;
			}

			++i;
		}

		return true;
    }
};