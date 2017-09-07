#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		std::sort(begin(g), end(g));
		std::sort(begin(s), end(s));
		
		int child = 0;
		for (int cookie = 0; child < g.size() && cookie < s.size(); cookie++)
			if (s[cookie] >= g[child])
				++child;

		return child;
    }
};