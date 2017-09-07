#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int ways = 0;
        climb(0, n, ways);
        return ways;
    }
    
	//a faster algorithm
	int climbS(int n)
	{
		int a = 1, b = 1;
		while (n--)
			a = (b += a) - a;
		return a;
	}

	//by gtk
    void climb(int index, int n, int& ways)
    {
        if (index > n)
            return;
        if (index == n)
        {
            ways++;
            return;
        }
        
        for (int i = 1; i<=2; i++)
            climb(index+i, n, ways);
    }
};