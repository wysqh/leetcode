#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		sort(begin(nums), end(nums));
		int index = 0;
		vector<int> result(nums.size()/2);
		std::copy_if(nums.begin(), nums.end(), result.begin(),[&index](int x)->bool{
			return (index++ % 2 == 0);
		});

		return std::accumulate(result.begin(), result.end(), 0);
    }
};