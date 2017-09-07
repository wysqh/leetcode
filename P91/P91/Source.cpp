#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
//7.83%

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
		unordered_map <string, int> str2int;
		int size = generate(s, str2int);;
		return size;
    }

	int generate(string s, unordered_map<string, int> &str2int)
	{
		int l = 0, r = 0;
		if (s.empty())
		{
			str2int.insert(pair<string, int>(s, 1));
			return 1;
		}

		string c = s.substr(0, 1);
		if ( atoi(c.c_str()) >= 1 && atoi(c.c_str()) <= 26)
		{
			if (str2int.find(s) == str2int.end())
				l = generate(s.substr(1), str2int);
			else
				return str2int[s];
		}

		if (s.size() >= 2)
		{
			string c2 = s.substr(0, 2);
			if (c2 < "10" || c2 > "26")
				return l;

			if (str2int.find(s) == str2int.end())
				r = generate(s.substr(2), str2int);
			else 
				return str2int[s];
		}

		str2int.insert(pair<string, int>(s, l+r));
		return l+r;
	}
};
int main()
{
	Solution a;
			
	cout << a.numDecodings("1322") << endl;
	return 0;
}