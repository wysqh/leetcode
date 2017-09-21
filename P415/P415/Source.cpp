#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
		int carry = 0;
        string ans(max(num1.size(), num2.size())+1, '0');
        std::reverse(begin(num1), end(num1));
        std::reverse(begin(num2), end(num2));
        int i = 0;
        for (i = 0; i < num1.size() && i < num2.size(); i++)
        {
            int num = (num1[i] - '0') + (num2[i] - '0') + carry;
            ans[i] += num % 10;
            carry = num / 10;
        }
        while(i < num1.size())
        {
            int num = (num1[i] - '0') + carry;
            ans[i] += num % 10;
            carry = num / 10;
            i++;
        }
        while(i < num2.size())
        {
            int num = (num2[i] - '0') + carry;
            ans[i] += num % 10;
            carry = num / 10;
            i++;
        }
        ans.back() += carry;
        
        std::reverse(begin(ans), end(ans));
        size_t startpos = ans.find_first_not_of("0");
        if (startpos != string::npos)
            return ans.substr(startpos);
        
        return "0";
	}
};
//
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//		int carray = 0;
//		int n1, n2;
//		string res = "";
//		for (n1 = num1.size()-1, n2 = num2.size()-1; n1 >= 0 && n2 >=0; n1--, n2--)
//		{
//			int add1 = num1[n1] - '0';
//			int add2 = num2[n2] - '0';
//			if (add1 + add2 + carray >= 10)
//			{
//				res += to_string(add1+add2+carray-10);
//				carray = 1;
//			}
//			else
//			{
//				res += to_string(add1+add2+carray);
//				carray = 0;
//			}
//		}
//		if (n1 >= 0)
//		{
//			while (n1 >= 0)
//			{
//				int add1 = num1[n1] - '0';
//				if (carray + add1 >= 10)
//				{
//					res += to_string(carray + add1 - 10);
//					carray = 1;
//				}
//				else
//				{
//					res += to_string(carray + add1);
//					carray = 0;
//				}
//				--n1;
//			}
//		}
//		else
//		{
//			while (n2 >= 0)
//			{
//				int add1 = num2[n2] - '0';
//				if (carray + add1 >= 10)
//				{
//					res += to_string(carray + add1 - 10);
//					carray = 1;
//				}
//				else
//				{
//					res += to_string(carray + add1);
//					carray = 0;
//				}
//				--n2;
//			}
//		}
//		if (carray)
//			res += "1";
//
//		std::reverse(res.begin(), res.end());
//		return res;
//	}
//};

int main()
{
	Solution s;
	cout << s.addStrings("0","0") << endl;
	return 0;
}