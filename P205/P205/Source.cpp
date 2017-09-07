#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;

		unordered_map<char, char> res;
		for (int i = 0; i < s.size(); i++)
		{
			if (res.find(s[i]) == res.end())
            {
                if (find_if(begin(res), end(res), [&](pair<char, char> p)->bool{
                    return p.second == t[i];
                }) != end(res))
                {
                    return false;        
                }
				res[s[i]] = t[i];
            }
			else
			{
				if (res[s[i]] != t[i])
					return false;
			}
		}

		return true;
    }
};

int main()
{
	Solution s;
	cout << s.isIsomorphic("ab", "aa");
}