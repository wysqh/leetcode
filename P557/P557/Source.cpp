#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
		stringstream ss(s);
		string word, res;
		while (ss >> word)
		{
			std::reverse(begin(word), end(word));
			res += word + " ";
		}
		
		return res.substr(0, res.size()-1);
	}
};