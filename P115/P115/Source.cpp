#include <vector>
#include <iostream>
#include <string>

using namespace std;

//16.01%

class Solution {
public:
    int numDistinct(string s, string t) {
		int size1 = s.size() + 1, size2 = t.size() + 1;
		
		vector<vector<int>> dp(size1, vector<int>(0,));
		for (int i = 0; i < size1; ++i)
			for (int j = 0; j < size2; ++j)
			{
				if ( i == 0 && j == 0)
					dp[i][j] = 0;
				else if (i == 0)
					dp[i][j] = 0;
				else if (j == 0)
					dp[i][j] = 1;
				else 
					dp[i][j] = dp[i-1][j] + s[i-1] == t[j-1] ? dp[i-1][j-1] : 0;
				
			}

			return dp[size1][size2];
    }
};