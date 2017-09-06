#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	void findSequence(int index, int total, deque<int>&list, vector<vector<int>>& numbers, int &sum)
	{
		if (index == total)
		{
			sum = sum + 1;
			return;
		}

		for (auto& e: numbers[index])
			if (find(begin(list), end(list), e) == end(list))
			{
				list.push_back(e);
				findSequence(index + 1, total, list, numbers, sum);
				list.pop_back();
			}
	}
};

int main()
{
	int a[][6] = { 
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5},
		{0,1,2,3,4,5}
	};

	vector<vector<int>> test(6);	//Èý¸ö¹¥³ÇÊ¨
	for (int i = 0; i < test.size(); i++)
		test[i].assign(begin(a[i]), end(a[i]));

	int sum = 0;
	Solution s;
	deque<int> que;
	s.findSequence(0, test.size(), que, test, sum);
	cout << sum << endl;
}