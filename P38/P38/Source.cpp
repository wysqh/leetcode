#include <iostream>
#include <string>
#include <vector>

using namespace std;


//32.68%

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
			return string("1");

		string say = countAndSay(n-1);
		string word = "";
		char cnt = '0';
		for (int i = 0; i < say.size(); i++)
		{
			cnt = cnt + 1;
			char c = say.at(i);
			if (say.size() == i + 1 || c != say.at(i+1))
			{
				word += cnt;
				word += c;
				cnt = '0';
			}
		}

		return word;
    }
};

int main()
{
	Solution solution;
	cout << solution.countAndSay(5) << endl;
	return 0;
}