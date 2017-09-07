#include <iostream>
#include <vector>
#include <string>

using namespace std;

//2.8%

class Solution {
public:
    int uniquePaths(int m, int n) {
		//return solve(0, 0, m - 1, n - 1);

		//return factorial(m+n-2)/(factorial(m-1)*factorial(n-1));

		vector<vector<int>> triangle(m, vector<int>(n, 1));
		for (int i = 1; i < triangle.size(); i++)
			for (int j = 1; j < triangle[i].size(); j++)
				triangle[i][j] = triangle[i-1][j] + triangle[i][j-1];

		return triangle[m-1][n-1];
    }

	int solve(int curM, int curN, int m, int n)
	{
		int l = 0, r = 0;
		if (curM == m && curN == n)
			return 1;

		if (curM + 1 <= m)
			l = solve(curM + 1, curN, m ,n);
		if (curN + 1 <= n)
			r = solve(curM, curN + 1, m, n);

		return l + r;
	}

	int factorial(int n)
	{
		if ( n == 0 )
			return 1;

		long long sum = n;
		for (int i = n - 1; i >= 1; --i)
			sum *= i;

		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.uniquePaths(1, 3) << endl;
	return 0;
}