#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
};


int main()
{
	vector<vector<int>> test;
	vector<int> a;
	a.push_back(0);
	a.push_back(1);
	vector<int> b;
	b.push_back(1);
	b.push_back(0);

	test.push_back(a);
	test.push_back(b);
	Solution s;
	s.uniquePathsWithObstacles(test);
	return 0;
}