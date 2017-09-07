#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
			return false;
    
		int sum = 1;
		for (int divisor = 2; divisor <= (int)sqrt(num); divisor++)
			if (num % divisor == 0)
				sum += divisor + (num / divisor == divisor ? 0 : num / divisor);

		return sum == num;
	}
};
