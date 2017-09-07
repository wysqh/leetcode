#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		vector<int> tmp(begin(nums), end(nums));
		std::make_heap(begin(nums), end(nums));
		vector<int> max3nums(3, 0);
		vector<int> min3nums(3, 0);
		min3nums[0] = nums.front();
		for (int i = 0; i < 3; i++)
		{
			max3nums[i] = nums.front();
			std::pop_heap(nums.begin(), nums.end());
			nums.pop_back();
		}
		std::function<bool(int, int)> comp = [](int a, int b) -> bool{
			return (a > b);
		};
		std::make_heap(begin(tmp), end(tmp), comp);
		for (int i = 1; i < 3; i++)
		{
			min3nums[i] = tmp.front();
			std::pop_heap(tmp.begin(), tmp.end(), comp);
			tmp.pop_back();
		}
		std::function<int(int, int)> multi = [](const int a, const int b) -> int {
			return a*b;
		};
		return max(std::accumulate(begin(min3nums), end(min3nums), 1, std::multiplies<int>()),
			std::accumulate(begin(max3nums), end(max3nums), 1, multi));
    }
};

int main()
{
	
}