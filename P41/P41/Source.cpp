#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

//13.13%

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int rtValue = 1;
		int maxV;
		vector<int>::iterator it;

		sort(begin(nums), end(nums));
		it = max_element(begin(nums), end(nums));
		maxV = (it != end(nums)) ? (*it) : -1;
		for (int i = 1; i <= maxV + 1; i++)
		{
			if (find(begin(nums), end(nums), i) == end(nums))
			{
				rtValue =  i;
				break;
			}
		}

		return rtValue;
    }
};

int main()
{
	int a[] = {3,4,-1,-2,1,2};
	Solution solution;
	cout << solution.firstMissingPositive(vector<int>(begin(a), end(a))) << endl;
	return 0;
}