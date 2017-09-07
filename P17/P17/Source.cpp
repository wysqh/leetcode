#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

/*
	Given a digit string, return all possible letter combinations that the number could represent.

	A mapping of digit to letters (just like on the telephone buttons) is given below.

	Input:Digit string "23"
	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

// 1.83%

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> mapping;
		vector<string> rtValue;
		vector<string> ch;
		if (digits.size() == 0)
			return rtValue;
		mapping.insert(pair<int ,string>(1, ""));
		mapping.insert(pair<int ,string>(2, "abc"));
		mapping.insert(pair<int ,string>(3, "def"));
		mapping.insert(pair<int ,string>(4, "ghi"));
		mapping.insert(pair<int ,string>(5, "jkl"));
		mapping.insert(pair<int ,string>(6, "mno"));
		mapping.insert(pair<int ,string>(7, "pqrs"));
		mapping.insert(pair<int ,string>(8, "tuv"));
		mapping.insert(pair<int ,string>(9, "wxyz"));
		for (auto digit : digits)
		{
			int number = digit - '0';
			ch.push_back(mapping.at(number));
		}

		combination(ch, rtValue, 0, "");

		return rtValue;
    }

	void combination(vector<string> ch, vector<string>&rtValue, int index, string passing)
	{
		for (int i = 0; i < ch[index].size(); i++)
		{
			if (index == ch.size() - 1)
			{
				rtValue.push_back(passing+=ch[index].at(i));
				passing.erase(passing.size()-1);
				continue;
			}

			combination(ch, rtValue, index + 1, passing + ch[index].at(i));
		}
	}
};

int main()
{
	Solution solution;
	vector<string> test;
	test = solution.letterCombinations("");
	for (auto e: test)
		cout << e << endl;
	return 0;
}