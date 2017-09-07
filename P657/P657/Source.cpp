#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        struct Order{
			char ch;
			pair<int, int> point;
		} order[] = {
			{'R', make_pair(1, 0)},
			{'L', make_pair(-1, 0)},
			{'U', make_pair(0, -1)},
			{'D', make_pair(0, 1)}
		};

		unordered_map<char, pair<int, int>> res;
		for (int i = 0; i < 4; i++)
			res[order[i].ch] = order[i].point;

		pair<int, int> ori = make_pair(0, 0);
		for(int i = 0; i < moves.size(); i++)
		{
			auto ref = res.find(moves[i]);
			ori.first += ref->second.first;
			ori.second += ref->second.second;
		}

		return ori.first == 0 && ori.second == 0;
    }
};