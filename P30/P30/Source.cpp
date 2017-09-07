#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*	
	You are given a string, s, and a wordsist of words, words, that are all of the same length. 
	Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

	For example, given:
	s: "barfoothefoobarman"
	words: ["foo", "bar"]

	You should return the indices: [0,9].
	(order does not matter).
*/

//¡¡Hard
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
                vector<int> ans;
		int n = s.size(), cnt = words.size();
        if (n <= 0 || cnt <= 0) return ans;
        
        // init word occurence
        unordered_map<string, int> dict;
		for (int i = 0; i < cnt; ++i) dict[words[i]]++;
        
        // travel all sub string combinations
        int wl = words[0].size();
        for (int i = 0; i < wl; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j <= n - wl; j += wl) {
                string str = s.substr(j, wl);
                // a valid word, accumulate results
                if (dict.count(str)) {
                    tdict[str]++;
                    if (tdict[str] <= dict[str]) 
                        count++;
                    else {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str]) {
                            string str1 = s.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        ans.push_back(left);
                        // advance one word
                        tdict[s.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                // not a valid word, reset all vars
                else {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        
        return ans;
    }
};

int main()
{

	return 0;
}