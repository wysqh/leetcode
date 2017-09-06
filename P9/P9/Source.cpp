#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Determine whether an integer is a palindrome. Do this without extra space.

	click to show spoilers.

	Subscribe to see which companies asked this question.
*/

class Solution {
public:
    bool isPalindrome(int x) {
		bool bPalindrome = true;
		string str = to_string(x);
		int head = 0;
		int tail = str.size() - 1;
		int middle = str.size() / 2;
		if (str.size() % 2 == 0)
		{
			for (int i = 0; i < str.size() / 2; i++)
			{
				if ( str.at(middle-1-i) != str.at(middle+i) )
				{
					bPalindrome = false;
					break;
				}
			}
		}
		else 
		{
			for (int i = 0; i <= str.size() / 2; i++)
			{
				if ( str.at(middle-i) != str.at(middle+i) )
				{
					bPalindrome = false;
					break;
				}
			}
		}

		return bPalindrome;
    }
};

int main()
{
	Solution solution;
	cout << solution.isPalindrome(-10) << endl;
	return 0;
}