#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty())
			return 0;

		vector<int> diff(nums.size());
		vector<int>::iterator bound = std::adjacent_difference(begin(nums), end(nums), begin(diff));
		vector<int> none0diff;
		for_each(begin(diff)+1, end(diff), [&none0diff](int x) ->void{
			if (x != 0)
				none0diff.push_back(x);
		});
		if (none0diff.size() <= 1)
			return 1;

		int ori = none0diff[0];
		int maxN = 2;
		int base = 2;
		for (int i = 1; i < none0diff.size(); ++i)
		{
			if (ori*none0diff[i] < 0)
			{
				++base;
				ori = none0diff[i];
			}
		}
		return base;
    }
};

int main()
{
	Solution s;
	int a[] = {3,3,3,2,5};
	vector<int>test(begin(a), end(a));
	cout << s.wiggleMaxLength(test) << endl;
}