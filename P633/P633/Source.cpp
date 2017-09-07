#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0)
			return false;

		unordered_map<int, int> res;
		for (int k = 0; k <= (int)sqrt(c); k++)
		{
			if (2*k*k == c)
				return true;

			if (res.find(c-k*k) == res.end())
				res[k*k] = k*k;
			else return true;
		}
	
		return false;
    }
};