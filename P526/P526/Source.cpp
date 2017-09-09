#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<bool> used;
    int countArrangement(int N) {
		used.assign(N+1, false);
		int sum = 0;
		helper(1, N, sum);

		return sum;
    }

	void helper(int index, int& N, int &sum)
	{
		if (index == N + 1)
		{
			++sum;
			return;
		}

		for (int i = 1; i <= N; ++i)
			if (!used[i] && (i%index == 0 || index%i == 0))
			{
				used[i] = true;
				helper(index+1, N, sum);
				used[i] = false;
			}
	}
};