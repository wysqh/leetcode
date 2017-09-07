#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
		int size = candies.size() / 2;
		std::sort(begin(candies), end(candies));
		auto bound = std::unique(begin(candies), end(candies));
		candies.resize(std::distance(candies.begin(), bound));

		return candies.size() >= size ? size : candies.size();
    }
};