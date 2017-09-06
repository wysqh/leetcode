#include <iostream>
#include <string>
using namespace std;
//34.78%
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        int pt1 = 0; int pt2 = s.size() - 1;
        while(pt1 < pt2)
        {
            while(pt1 < pt2 && !isalnum(s[pt1]))
            {
                pt1++;
            }
            while(pt1 < pt2 && !isalnum(s[pt2]))
            {
                pt2--;
            }
            if(pt1 < pt2 && tolower(s[pt1++]) != tolower(s[pt2--])) return false;
        }
        return true;
        
    }
};