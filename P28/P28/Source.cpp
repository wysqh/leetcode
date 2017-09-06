#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	Implement strStr().

	Returns the index of the first occurrence of needle in haystack, 
	or -1 if needle is not part of haystack.
*/

//22.65%

class Solution {
public:
    int strStr(string haystack, string needle) {
		return haystack.find(needle);
    }
};

int main()
{
	return 0;
}