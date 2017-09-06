#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//39.81%

class Solution {
public:
    int lengthOfLastWord(string s) {
		reverse(begin(s), end(s));
		
		int cnt = 0;

		size_t pos = s.find_first_not_of(' ');
		if (string::npos == pos)
		    return cnt;
		    
		for (auto e: s.substr(pos))
			if ( e != ' ')
				cnt = cnt + 1;
			else break;

		return cnt;
    }
};

int main()
{
	Solution s;
	cout << s.lengthOfLastWord("a ");
	return 0;
}