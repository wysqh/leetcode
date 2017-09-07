#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

//0.43%

class Solution {
public:
  //  vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//vector<vector<string>> rtvalue;
		//set<string> mapping;
		//vector<string> copy;
		//for (auto str : strs)
		//{
		//	sort(begin(str), end(str));
		//	mapping.insert(str);
		//	copy.push_back(str);
		//}
		//
		//for (set<string>::iterator it = mapping.begin(); it != mapping.end(); it++)
		//{
		//	vector<string> str;
		//	for (int j = 0; j < strs.size(); j++)
		//		if (*it == copy.at(j))
		//			str.push_back(strs.at(j));

		//	rtvalue.push_back(str);
		//}

		//return rtvalue;
  //  }

	 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) {  //auto: 指代map的迭代器iterator
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};

int main()
{
	//int a[] = {6,7,2,1,1,1,2,3,4,5,6,6,6,7,7,8,8,9};
	//vector<int> test(begin(a), end(a));
	//vector<int>::iterator endpos = unique(begin(test), end(test));

	//for (vector<int>::iterator it = test.begin(); it != endpos; it++)
	//	cout << *it << endl;
	/*Solution s;
	string a[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> test(begin(a), end(a));
	s.groupAnagrams(test);
	cout << endl;*/
	int a = 34 ^ 50 ^ 32;
	cout << a;
}