#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int> rn, mg;
		for (const auto& e: ransomNote)
			++rn[e];
		for (const auto&e : magazine)
			++mg[e];

		for (int i = 0; i < ransomNote.size(); ++i)
		{
			auto it = mg.find(ransomNote[i]);
			if (it == mg.end())
				return false;

			if (rn[ransomNote[i]] > it->second)
				return false;
		}

		return true;
    }
};