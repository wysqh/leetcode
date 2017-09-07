#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		string rtValue ;
		string ch = "";
		int cur = 0;
		solve(0, n, ch, cur, k, rtValue);

		return rtValue;
    }

	void solve(int index, int n, string result, int& ck, int k, string& rtValue)
	{
		if(index == n)
		{
			ck = ck + 1;	
			if (ck == k)
				rtValue = result;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (result.find_first_of(char('1'+i)) != string::npos)
				continue;

			solve(index+1, n, result+(char)('1'+i), ck, k, rtValue);
			if (ck == k)
				break;
		}
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(9, 21778) << endl;
}