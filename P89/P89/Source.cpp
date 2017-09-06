/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

Subscribe to see which companies asked this question.
*/

/*
000 0
001 1
011 3
111 7
110 6
100 4
101 5
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


//14.76%

class Solution {
public:
    vector<int> grayCode(int n) {
		vector<int> codes;
		if (n == 0)
		{
			codes.push_back(0);
			return codes;
		}

		generate(codes, n);
		return codes;
    }

	void generate(vector<int>& codes, int n)
	{
		if (n == 1)
		{
			codes.push_back(0);
			codes.push_back(1);

			return;
		}

		generate(codes, n-1);
		int size = codes.size();
		for (int i = size - 1; i >=0; --i)
			codes.push_back(codes.at(i));

		for (int i = 0; i < pow(2, n); i++)
			if ( i >= pow(2, n-1))
				codes.at(i) = codes.at(i) + pow(2, n-1);
	}
};

int main()
{
	Solution s;
	vector<int> ss;
	ss = s.grayCode(3);
	for (auto e: ss)
		cout << e << " " << endl;
	return 0;
}