#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

	For "(()", the longest valid parentheses substring is "()", which has length = 2.

	Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

	Subscribe to see which companies asked this question.
*/

//88.29%  with help

class Solution {
public:
#define MAX(x, y)	(x) > (y) ? (x) : (y)
    int longestValidParentheses(string s) {
		int maxValue = 0;
		vector<int> rtValue;
		if (s.size() == 0)
			return 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) == '(')	rtValue.push_back(i);
			else
			{
				if ( rtValue.size() == 0)	rtValue.push_back(i);
				else
				{
					if (s.at(rtValue.at(rtValue.size() - 1)) == '(')
						rtValue.pop_back();
					else
						rtValue.push_back(i);
				}
			}
		}

		//关于相减值得注意边界条件

		if (rtValue.empty()) maxValue = s.size();
        else 
		{
			int a = s.size(), b = 0;
			while (!rtValue.empty()) {
				b = rtValue.at(rtValue.size()-1); 
				rtValue.pop_back();
                maxValue = MAX(maxValue, a-b-1);
                a = b;
            }
            maxValue = MAX(maxValue, a);
        }

		return maxValue;
    }
};

int main()
{
	Solution solution;
	cout << solution.longestValidParentheses("(()") << endl;
	return 0;
}