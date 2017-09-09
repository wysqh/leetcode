#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 0), C(nums.size(), 0), D(nums.size(), 0);
		C[0] = 1;
		for (int i = 1; i < res.size(); i++)
			C[i] = C[i-1] * nums[i-1];
		D.back() = 1;
		for (int i = nums.size() - 2; i >= 0; i--)
			D[i] = D[i+1] * nums[i+1];

		for (int i = 0; i < nums.size(); i++)
			res[i] = C[i] * D[i];

		return res;
    }
};
