#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

struct Member
{
	int id;
	int gender;
	int height;

	Member(int _id, int _gender, int _height) : id(_id), gender(_gender), height(_height)
	{
	}
};

bool compare(const Member& a, const Member& b)
{
	return a.height < b.height;
}
//4
//1 MALE 170
//2 FEMALE 180
//3 MALE 190
//4 FEMALE 200
//20
class Solution
{
public:
	int find(string a, string b)
	{
		int decial_a = strtoul(a.c_str(), nullptr, 7);
		int decial_b = strtoul(b.c_str(), nullptr, 7);
		int c = decial_a * decial_b;
		int power = 1;
		while (pow(7, power) < c)
			power++;

		string s ="";
		string ans = "";
		recursive(c, ans, power - 1, ans);
		return atoi(ans.c_str());
	}

	void recursive(int c, string s, int power, string &ans)
	{
		if (power == -1)
			return;

		for (int i = 6; i >=0; i--)
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
	/*Solution solution;
	string a, b;
	cin >> a >> b;
	cout << solution.find(a, b) << endl;*/
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	//a.clear();
	cout << a[1];
	return 0;
}

