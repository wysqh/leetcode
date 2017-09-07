/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int sumGas = 0;
		int sumCost = 0;
		for_each(begin(gas), end(gas), [&sumGas](int x){ sumGas += x; });
		for_each(begin(cost), end(cost), [&sumCost](int x) {sumCost += x;});
		if (sumGas < sumCost)
			return -1;

		for (int i = 0; i < gas.size(); ++i)
		{
			int left = 0;
			for (int count = 0; count <= gas.size(); ++count)
			{
				if (count != 0)
				{
					if (left - cost[(i+count-1)%gas.size()] < 0)	break;
					else left -= cost[(i+count-1)%gas.size()];
				}
				if (count == gas.size())
					return i;

				left += gas[(i+count)%gas.size()];
			}
		}

		return -1;
    }
};