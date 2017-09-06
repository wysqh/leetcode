#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int max = 0;
		stack<int> peaks;

		for (int i = 0; i < heights.size(); i++)
		{
			if (peaks.empty() || heights.at(i) >= heights[peaks.top()])
				peaks.push(i);
			else
			{
				while (!peaks.empty() && heights[peaks.top()] > heights.at(i))
				{
				    int left;
					int val = peaks.top();
					peaks.pop();
					
					if (peaks.empty())  left = 0;
					else    left = peaks.top() + 1;
					
					int area = (i-val-1) * heights[val] + heights[val] + (val-left) * heights[val];
					max = max >= area ? max : area;
				}
				peaks.push(i);
			}
		}

		return max;

    }
};

int main()
{
	stack<int> ss;
	int a[] = {2,5,6,4};
	vector<int> test(begin(a), end(a));

	Solution s;
	s.largestRectangleArea(test);
}