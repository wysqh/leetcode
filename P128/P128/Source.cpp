#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//65.84%

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int max = INT_MIN;
		unordered_map<int, int> um;
		for (auto& e: nums)
			um.insert(pair<int, int>(e, 1));

		for (auto& e: nums)
		{
			int length = 1;
			if (um.find(e) == um.end())
				continue;
			unordered_map<int,int>::iterator it;
			int cpy = e;
			while ((it = um.find(--cpy)) != um.end())
			{
				um.erase(it);
				length++;
			}
			cpy = e;
			while ((it = um.find(++cpy)) != um.end())
			{
				um.erase(it);
				length++;
			}
			max = max > length ? max : length;
		}

		return max;
    }
};

int main()
{
}