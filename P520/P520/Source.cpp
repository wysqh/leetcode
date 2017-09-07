#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag1 = true, flag2 = true, flag3 = true;
		for (const auto& e: word)
			if (e < 'A' || e > 'Z')
			{
				flag1 = false;
				break;
			}

		for (const auto& e: word)
			if ( e<= 'Z' && e >= 'A')
			{
				flag2 = false;
				break;
			}

		for(int i = 0; i < word.size(); ++i)
		{
			if (i == 0)
			{
				if(word[i] > 'Z' || word[i] < 'A')
				{
					flag3 = false;
					break;
				}
			}
			else
			{
				if (word[i] >= 'A' && word[i] <= 'Z')
				{
					flag3 = false;
					break;
				}
			}
		}

		return flag1 || flag2 || flag3;
	}
};

int main()
{
	Solution s;
	s.detectCapitalUse("Leetcode");
}
