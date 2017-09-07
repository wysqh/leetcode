#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string res = "";
		
		while (n)
		{
			res += (n-1) % 26 + 'A';
			n = (n-1) / 26;
		}

		std::reverse(res.begin(), res.end());
		return res;
    }
};

int main()
{
	Solution s;
	for (int i = 1; i <= 53; i++)
		cout << s.convertToTitle(i) << endl;
}