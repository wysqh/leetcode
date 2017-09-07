#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> maps;
		vector<string> list;
		string row[] = {"QWERTYUIOPqwertyuiop",
						"ASDFGHJKLasdfghjkl",
						"ZXCVBNM<zxcvbnm"};
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < row[i].size(); j++)
				maps.insert(make_pair(row[i][j], i));

		for (int i = 0; i < words.size(); i++)
		{
			if (words[i].size() <= 1)
			{
				list.push_back(words[i]);
				continue;
			}

			char ch = words[i][0];
			bool bFind = true;
			for (int j = 1; j < words[i].size(); j++)
				if (maps.find(words[i][j])->second != maps.find(ch)->second)
				{
					bFind = false;
					break;
				}

			if (bFind)	list.push_back(words[i]);
		}

		return list;
    }
};

int main()
{
	vector<string> test;
	test.push_back("dad");
	Solution s;
	vector<string> a = s.findWords(test);
	for (const auto& ele: a)
		cout << ele.c_str() << " ";
	cout << endl;

	return 0;
}