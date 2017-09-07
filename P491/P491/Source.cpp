#include <iostream>
#include <unordered_set>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> seq;
		dfs(res, seq, nums, 0);
		return res;
    }

	 void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) 
	 {
		 if (seq.size() >= 2) res.push_back(seq);

		 unordered_set<int> hash;
		 for (int i = pos; i < nums.size(); ++i)
			 if (seq.empty() || nums[i] >= seq.back()  && hash.find(nums[i]) == hash.end())
			 {
				 seq.push_back(nums[i]);
				 dfs(res, seq, nums, i+1);
				 seq.pop_back();
				 hash.insert(nums[i]);
			 }
	 }
};

int main()
{
	list<int> ls;
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	for (const auto&e: ls)
		cout << &e << " ";
	cout << endl;
	ls.erase(++begin(ls));
	for (const auto&e: ls)
		cout << &e << " ";
	return 0;
}