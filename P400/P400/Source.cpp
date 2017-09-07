#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int base = 9, digit = 1;
		while ((double)n-(double)base*digit>0)
		{
			n -= base*digit;
			++digit;
			base*=10;
		}

		int gap = (n-1) / digit;
		int index = n % digit;
		string number = to_string((int)pow(10, digit-1) + gap);
	
		return index == 0 ? number.back() - '0' : number[index-1] - '0';
	}
};

int main()
{
	Solution s;
	s.findNthDigit(1000000000);
}