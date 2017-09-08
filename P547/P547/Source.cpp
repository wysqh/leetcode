#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<bool> visited;
    int findCircleNum(vector<vector<int>>& M) {
		if (M.empty())
			return 0;

		visited.assign(M.size(), false);
		int count = 0;
		for (int i = 0; i < M.size(); i++)
			count += (!visited[i] ? dfs(M, i), 1 : 0);

		return count;
	}

	void dfs(vector<vector<int>>& M, int index)
	{
		visited[index] = true;
		for (int i = 0; i < M.size(); i++)
			if (i != index && M[index][i] && !visited[i])
				dfs(M, i);
	}
};

//mvbn,./.mnvcxzSDFHJKLP[]

//>
//UnionFind
//
//class Solution {
//public:
//    int findCircleNum(vector<vector<int>>& M) {
//        if (M.empty()) return 0;
//        int n = M.size();
//
//        vector<int> leads(n, 0);
//        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves
//
//        int groups = n;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
//                if (M[i][j]) {
//                    int lead1 = find(i, leads);
//                    int lead2 = find(j, leads);
//                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
//                        leads[lead1] = lead2;
//                        groups--;
//                    }
//                }
//            }
//        }
//        return groups;
//    }
//
//private:
//    int find(int x, vector<int>& parents) {
//        return parents[x] == x ? x : find(parents[x], parents);
//    }
//};