#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
	unordered_map<int, int> res;

    int numberOfArithmeticSlices(vector<int>& A) {
		if (A.empty())
			return 0;

		vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));		
		for (int len = 1; len <= A.size(); ++len)
			for (int i = 0; i + len <= A.size(); ++i)
			{
				int j = i + len - 1;
				if (j - i < 2)
					dp[i][j] = 0;
				else if (j - i == 2)
					dp[i][j] = isEqDiff(A, i, j) ? 1 : 0;
				else 
				{
					int carry = 0;
					if (res.find(i) != res.end())
					{
						if (j - res[i] == 1 && (A[j] - A[res[i]] == 
							A[res[i]] - A[res[i] - 1]))
						{
							carry = 1;
							res[i] = j;
						}
					}
					dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
					+ carry;
				}
			}
		
		return dp[0].back();
	}



	bool isEqDiff(vector<int>& A, int start, int end)
	{
		vector<int> diff(end-start+1);
		std::adjacent_difference(begin(A)+start, begin(A)+end+1, begin(diff));
		
		for (int i = 1; i < diff.size() - 1; ++i)
			if (diff[i] != diff[i+1])
				return false;

		res[start] = end;
		return true;
	}
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
		if (A.empty())
			return 0;

		vector<int> dp(A.size(), 0);
		dp[0],dp[1] = 0;
		for (int i = 2; i < A.size(); ++i)
			if (A[i] - A[i-1] == A[i-1] - A[i-2])
				dp[i] = dp[i-1] + 1;
			else dp[i] = 0;

		return std::accumulate(begin(dp), end(dp), 0, std::plus<int>());
	}
};