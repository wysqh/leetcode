#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> pairs = countWeight(strs);
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for (const auto& e: pairs)
			for (int i = m; i >= e.first; i--)
				for (int j = n; j >= e.second; j--)
				{
					dp[i][j] = max(dp[i][j], dp[i-e.first][j-e.second] + 1);
				}

		return dp[m][n];
    }

	vector<pair<int, int>> countWeight(vector<string> & strs)
	{
		vector<pair<int, int>> pairs;
		for (const string& str: strs)
		{
			int size = str.size();
			int num_of_zero = 0;
			for (const char& c : str)
				if (c == '0')	
					num_of_zero++;
			pair<int, int> tmp = make_pair(num_of_zero, size - num_of_zero);
			pairs.push_back(tmp);
		}

		return pairs;
	}
};