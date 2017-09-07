#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		stringstream ss(str);
		string buf;
		vector<string> strs;

		while (ss >> buf)
			strs.push_back(buf);

		if (pattern.size() != strs.size())
			return false;

		unordered_map<string, char> maps;
		for (int i = 0; i < strs.size(); i++)
		{
			if (maps.find(strs[i]) == maps.end())
			{
				if (find_if(begin(maps), end(maps), [&](const pair<string, char> p)->bool{
					return p.second == pattern[i];
				}) != end(maps))
					return false;
				maps.insert(make_pair(strs[i], pattern[i]));
			}
			else
			{
				if (maps.find(strs[i])->second != pattern[i])
					return false;
			}

		}

		return true;
    }
};

int main()
{
	string s = "abba";
	string sss = "dog cat cat dog";
	Solution solution;
	cout << solution.wordPattern(s, sss) << endl;
	return 0;
}