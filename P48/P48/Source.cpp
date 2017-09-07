#include <vector>
using namespace std;

//57.66%
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> tmp = matrix;
		int N = matrix.size();
		for(int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				matrix[N-1-j][i] = tmp[i][j];
			}
		}
    }
};