#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> ori = M;
		vector<vector<int>> results(M.size(), vector<int>(M[0].size(), 1));
		int dir[][2] = {{0, 1},{1, 1}, {1, 0}, {1, -1}, {0, -1},
			{-1, 0}, {-1, -1}, {-1, 1}};
		for(int i = 0; i < M.size() ; i++)
            for(int j = 0; j < M[0].size() ;j++)
				for (int k = 0; k < 8; k++)
				{
					if(!(i+dir[k][0]<0 || i+dir[k][0]>M.size()-1  || j+dir[k][1] > M[0].size()-1
						|| j+dir[k][1] < 0))
					{
						M[i][j] += ori[i+dir[k][0]][j+dir[k][1]];
						results[i][j]++;
					}
				}

		for(int i = 0; i < M.size() ; i++)  
            for(int j = 0; j < M[0].size() ;j++)
				M[i][j] = M[i][j] / results[i][j];

		return M;
	}
};