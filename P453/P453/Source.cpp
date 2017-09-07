#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
		auto minN = min_element(begin(nums), end(nums));

		for_each(begin(nums), end(nums), [&minN](int& x) -> void{
			x -= *minN;
		});

		return std::accumulate(begin(nums), end(nums), 0, std::plus<int>());
    }
};