#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
		unordered_map<int, int> res;
		while (res.find(cal(n)) == res.end())
		{
			int newNum = cal(n);
			if (cal(newNum) == 1)
				return true;

			n = newNum;
		}

		return false;
    }

	int cal(int n)
	{
		int sum = 0;
		while (n != 0)
		{
			int k = n % 10;
			sum += k * k;
			n /= 10;
		}

		return sum;
	}
};