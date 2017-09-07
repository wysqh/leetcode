#include <iostream>
#include <vector>

using namespace std;

// Thanks for idea 55.44%

class Solution {
public:
    int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int maxleft = 0, maxright = 0;
		int res = 0;

		while (left <= right)
		{
			if (height.at(left) <= height.at(right))
			{
				if (height.at(left) >= maxleft)	maxleft = height.at(left);
				else res += maxleft - height.at(left);
				left++;
			}
			else
			{
				if (height.at(right) >= maxright) maxright = height.at(right);
				else res += maxright - height.at(right);
				right --;
			}
		}

		return res;
    }
};

int main()
{

	return 0;
}