#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
		string vowels = "aeiouAEIOU";
		unordered_map<char, char> res;
		string word = "";

		for(int i = 0; i < vowels.size(); ++i)
			res[vowels[i]] = vowels[i];
			
		for(const auto&e : s)
			if (res.find(e) != res.end())
				word += e;
	
		int index = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++)
			if (res.find(*it) != res.end())
				*it = word[index++];

		return s;
	}
};