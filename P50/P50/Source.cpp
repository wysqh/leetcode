#include <iostream>
#include <vector>

using namespace std;

//注意指数为负数, 特殊数字0,1的Ｎ次方, 各种花式边界测试

//1.38%		//学习:快速幂算法　18.96%

class Solution {
public:
	 double myPow(double x, int n) {
    	double ans = 1;
    	unsigned long long p;
    	if (n < 0) {
    		p = -n;
    		x = 1 / x;
    	} else {
    		p = n;
    	}
		while (p) {
			if (p & 1)
				ans *= x;
			x *= x;
			p >>= 1;
		}
		return ans;
    }
};

int main()
{
	int n = -2147483648;

	cout << -n << endl;
}