#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        unordered_map<int, int> memo;
		return getAcount(1, n, memo);
    }

	int getAcount(int l, int r, unordered_map<int, int>& memo) {
	    int min = INT_MAX;
		if ( r - l == 2)
			return (r + l)/2;
		else if (r - l == 1)
			return l;
		else if (r - l <= 0)
			return 0;
		else if (memo.find(l*10+r) != memo.end())
		    return memo.at(l*10+r);
		else {
			for (int i = l ; i <= r; i++)
			{
				int tmp = i + max(getAcount(0, i - 1, memo), getAcount(i + 1 , r, memo));
				memo[l*10+r] = tmp;
				min = min < tmp ? min : tmp;
			}
			return min;
		}
	}
};


int main()
{
	Solution s;
	cout << s.getMoneyAmount(5) << endl;
	return 0;
}