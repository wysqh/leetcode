#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

namespace cus{
	int partition(vector<int>& nums, int l , int r)
	{
		int index = rand()%(r-l+1)+l;
		swap(nums[index], nums[r]);

		int small = l - 1;
		for (index = l; index < r; index++)
		{
			if (nums[index] > nums[r])
			{
				++small;
				if (small != index)
					swap(nums[small], nums[index]);
			}
		}
		++small;
		swap(nums[small], nums[r]);
		return small;
	}
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
		std::sort(begin(nums), end(nums)); //unique只去除连续重复
		vector<int>::iterator bound = std::unique(begin(nums), end(nums)); //返回尾迭代器
		nums.resize(std::distance(nums.begin(), bound));
		return select(nums, 0, nums.size()-1, 3);
    }

	int select(vector<int>& nums, int l, int r, int k)
	{
		int q = cus::partition(nums, l, r);
		int dex = q - l + 1;
		if (dex == k)
			return nums[q];
		else if (dex < k)
			return select(nums, q+1, r, k-dex);
		else return select(nums, l, q, k);
	}
};

