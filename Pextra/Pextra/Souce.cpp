#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
	vector<int> generate(string &input)
	{
		vector<int> rtValue;
		replace_if(input.begin(), input.end(), [](int x) mutable ->decltype(x=='5'){return x == '5';}, ' ');
		stringstream ss(input);
		string word;
		while(ss >> word)
			rtValue.push_back(atoi(word.c_str()));

		sort(begin(rtValue), end(rtValue));
		return rtValue;
	}
};

int main()
{
	string a = "555555555";
	Solution s;
	vector<int> test = s.generate(a);
	for (auto e: test)
		cout << e << endl;
}