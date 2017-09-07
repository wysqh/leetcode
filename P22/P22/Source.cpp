#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

	For example, given n = 3, a solution set is:

	[
	  "((()))",
	  "(()())",
	  "(())()",
	  "()(())",
	  "()()()"
	]
*/

//17.21%

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> result;
		vector<char> chSet;
		string passing = "";

		generate(passing, 0, 0, n, chSet, result);

		return result;
    }

	void generate(string passing, int index, int cnt, int n, vector<char> chSet, vector<string>& result)
	{
		if (index  == 2 * n - 1)
		{
			chSet.pop_back();
			result.push_back(passing + ')');
			return;
		}

		if (chSet.size() == 0)
		{
			chSet.push_back('(');
			generate(passing + '(', index+1, cnt + 1, n, chSet, result);
		}
		else
		{
			if (cnt < n)
			{
				chSet.push_back('(');
				generate(passing + '(', index + 1, cnt + 1, n, chSet, result);
				chSet.pop_back();
			}
			chSet.pop_back();
			generate(passing + ')', index + 1, cnt, n, chSet, result);
		}
	}
};

int main()
{
	Solution solution;
	vector<string> test = solution.generateParenthesis(2);
	for (auto e: test)
		cout << e << endl;
	return 0;
}