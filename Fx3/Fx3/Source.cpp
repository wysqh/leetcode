#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	unsigned long long find(string a, string b)
	{
		unsigned long long decial_a = strtoul(a.c_str(), nullptr, 7);
		unsigned long long decial_b = strtoul(b.c_str(), nullptr, 7);
		unsigned long long c = decial_a * decial_b;
		unsigned long long power = 1;
		while (pow(7, power) < c)
			power++;

		string s ="";
		string ans = "";
		recursive(c, ans, power - 1, ans);
		return atoi(ans.c_str());
	}

	void recursive(unsigned long long c, string s, unsigned long long power, string &ans)
	{
		if (power == -1)
			return;

		for (unsigned long long i = 6; i >=0; i--)
		{
			if (pow(7, power) * i > c)
				continue;

			ans = s+ to_string(i);
			return recursive(c-pow(7, power) * i, s+ to_string(i), power - 1, ans);
		}
	}
};

int main()
{
	Solution solution;
	string a, b;
	cin >> a >> b;
	cout << solution.find(a, b) << endl;
}