#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
	if (num > 6)
		return 1;
	else if (num < 6)
		return -1;
	else return 0;
};

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, h = n, mid, rtValue;
		while (l < h)
		{
		    mid = l + (h-l)/2;
			if ((rtValue =  guess(mid)) == -1)
				l = mid + 1;
			else if (rtValue == 1)
				h = mid;
			else return mid;
		}

		return l;
	}
};

int main()
{
	Solution ss;
	cout <<ss.guessNumber(10) << endl;
}