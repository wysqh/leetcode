#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) 
				continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

//class Solution {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//		set<vector<int>> rtValue;
//		vector<int> container;
//		map<int, int> ori;
//		map<int, int> cmp;
//
//		sort(begin(nums), end(nums));
//		for (auto e: nums)
//			ori[e]++;
//		
//		findAnswer(rtValue, nums, container, 0, ori, cmp);
//
//		return vector<vector<int>>(begin(rtValue), end(rtValue));
//    }
//
//	void findAnswer(set<vector<int>>& rtValue, vector<int> nums, vector<int> container, int index, map<int,int> ori, map<int, int> cmp)
//	{
//		if (index == nums.size())
//		{
//			rtValue.insert(container);
//			return;
//		}
//
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (cmp[nums.at(i)] >= ori[nums.at(i)])
//			{
//				continue;
//			}
//
//			cmp[nums.at(i)] = cmp[nums.at(i)] + 1;
//			container.push_back(nums.at(i));
//			findAnswer(rtValue, nums, container, index + 1, ori, cmp);
//			container.pop_back();
//			cmp[nums.at(i)] = cmp[nums.at(i)] - 1;
//		}
//	}
//};

int main()
{
	int a[] = {1,2,3};
	vector<vector<int>> r;
	vector<int> test(begin(a), end(a));
	Solution s;
	r = s.permuteUnique(test);

	for (auto vec : r)
	{
		for (auto e : vec)
			cout << e << " ";

		cout << endl;
	}
	return 0;
}
