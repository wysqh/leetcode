#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//12.92%

class Solution {
public:
    string simplifyPath(string path) {
		stack<string> ch;
		string single = "";
		bool spec = false;
		for (int i = 0; i < path.size(); i++)
		{
			char c = path.at(i);
			if (c == '/')
			{
				spec = false;
				if (i == 0)
				{
					ch.push("/");
					continue;
				}
				else
				{
					if (single.size())
					{
						ch.push(single);
						single.clear();
					}
					continue;
				}
			}
			if (c == '.' && !spec)
			{
				if ( i + 1 < path.size() && path.at(i+1) == '.' )
				{
					if (i + 2 == path.size() || path.at(i+2) == '/')
					{
						i++;
						if (ch.size() > 1)
							ch.pop();
						continue;
					}
					else spec = true;
				}
				else if (i + 1 == path.size() || path.at(i+1) == '/') continue;
			}
			single += c;
		}
		if (single.size())
			ch.push(single);

		vector<string> vec;
		string result;
		while (ch.size())
		{
			vec.push_back(ch.top());
			ch.pop();
		}

		if (!vec.size())
			result = "/";

		for (int i = vec.size() - 1; i >= 0; --i)
		{
			if (vec[i] == "/" || i == 0)
				result += vec[i];
			else 
				result += vec[i] + "/";
		}

		return result;
    }
};

int main()
{
	Solution s;

	cout << s.simplifyPath("/.hidden/test/../.") << endl;
	return 0;
}