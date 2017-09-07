#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

	Subscribe to see which companies asked this question.
*/

//2.40%

class Solution {
public:
    bool isValid(string s) {
		vector<char> chSet;
		bool rtValue = true;
		if (s.size() % 2 != 0)
			return false;

		for (auto e : s)
		{
			if (chSet.size() == 0)
			{
				push(chSet, e);
				continue;
			}

			char c = getTop(chSet);
			switch (e)
			{
			case ']':
				if (c != '[')
					return false;
				pop(chSet);
				break;
			case ')':
				if (c != '(')
					return false;
				pop(chSet);
				break;
			case '}':
				if (c != '{')
					return false;
				pop(chSet);
				break;
			default:
				push(chSet, e);
				break;
			}	
		}

		return (chSet.size() == 0 ? true : false);
    }

	void push(vector<char>& chSet, char c)
	{
		chSet.push_back(c);
	}

	void pop(vector<char>& chSet)
	{
		
		chSet.pop_back();
	}

	char getTop(vector<char>& chSet)
	{
		char c = chSet.at(chSet.size() - 1);
		return c;
	}
};

int main()
{

	return 0;
}