#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int product = 1;
		int ori = n;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;

		while (n != 0)
		{
			if (n - 3 >= 0)
			{
				n -= 3;
				product *= 3;
			}
			else if (n - 2 >= 0)
			{
				n -= 2;
				product *= 2;
			}
			else
			{
				product = product / 3 * 4;
				n = 0;
			}
		}
		return product;
    }
};

int main()
{
	Solution s;
	for (int i = 2; i <= 58; i++)
	{
		cout << i << ": " << s.integerBreak(i) << endl;
	}
}
