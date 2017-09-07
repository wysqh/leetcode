#include <iostream>
<<<<<<< HEAD
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		string res(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; --i)
=======
#include <string>
#include <vector>
using namespace std;

//71.33%

class Solution {
public:
    string multiply(string num1, string num2) {
		string rtValue(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >=0; --i)
>>>>>>> 2d86cdadada16552b9cf35a989a021746884a9c4
		{
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j)
			{
<<<<<<< HEAD
				int tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				res[i+j+1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			res[i] += carry;
		}

		size_t startpos = res.find_first_not_of("0");
		if (string::npos != startpos)
			return res.substr(startpos);

		return "0";
    }
};
=======
				int tmp = rtValue[i+j+1] - '0' + (num1.at(i) - '0') * (num2.at(j) - '0') + carry;
				rtValue[i+j+1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			
			rtValue[i] = carry + '0';
		}

		size_t pos = rtValue.find_first_not_of('0');
		if (string::npos != pos)
			return rtValue.substr(pos);

		return "0";
    }
};

int main()
{
	Solution s;
	cout << s.multiply("111","333") << endl;
	return 0;
}
>>>>>>> 2d86cdadada16552b9cf35a989a021746884a9c4
