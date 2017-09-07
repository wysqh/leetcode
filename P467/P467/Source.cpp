#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

/*
After failed with pure math solution and 
time out with DFS solution, I finally realized 
that this is a DP problem...
The idea is, if we know the max number of unique 
substrings in p ends with 'a', 'b', ..., 'z', then 
the summary of them is the answer. Why is that?

The max number of unique substring ends with a letter 
equals to the length of max contiguous substring ends 
with that letter. Example "abcd", the max number of 
unique substring ends with 'd' is 4, apparently they 
are "abcd", "bcd", "cd" and "d".
If there are overlapping, we only need to consider the
longest one because it covers all the possible substrings. 
Example: "abcdbcd", the max number of unique substring ends
with 'd' is 4 and all substrings formed by the 2nd "bcd" 
part are covered in the 4 substrings already.
No matter how long is a contiguous substring in p, it is 
in s since s has infinite length.
Now we know the max number of unique substrings in p ends
with 'a', 'b', ..., 'z' and those substrings are all in s. 
Summary is the answer, according to the question.
Hope I made myself clear...
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);

		if (p.empty())
			return 0;
		
		char ch = p[0];
		dp[ch-'a'] = 1;

		int suflength = 1;
		for (int i = 1; i < p.size(); ++i)
		{
			if (p[i] - ch == 1 || p[i] - ch == 'a' - 'z') suflength++;
			else suflength = 1;

			dp[p[i]-'a'] = max(dp[p[i]-'a'], suflength);
			ch = p[i];
		}

		return accumulate(begin(dp), end(dp), 0);
    }
};

int main()
{
	Solution ss;
	string s = "bcdbc";
	ss.findSubstringInWraproundString(s);
}