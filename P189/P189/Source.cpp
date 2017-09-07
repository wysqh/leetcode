#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int trk = nums.size() - (k % nums.size());
		vector<int> frontv(nums.begin(), nums.begin() + trk);
		vector<int> backv(nums.begin()+trk, nums.end());

		for(int i = 0; i < backv.size(); i++)
			nums[i] = backv[i];
		for (int i = 0; i < frontv.size(); i++)
			nums[i+backv.size()] = frontv[i];
    }
};