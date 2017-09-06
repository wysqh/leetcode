#include <algorithm>
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <cctype>

#define A 3+5
#define B A * A

using namespace std;

class Solution
{
public:
	void all_ofT()
	{
		std::array<int,8> foo = {3,5,7,11,13,17,19,23};
		if(std::all_of(foo.begin(), foo.end(), [](int i){return i%2;}))
			std::cout << "All odd" << endl;
	}

	static void fun(){};
	static void fun(int a){};
};

string test()
{
	return move(string("sss"));
}

int main()
{
	string a = test();
	cout << a << endl;

	vector<int> vec(1,2);
	cout << vec.capacity() << endl;
	cout << vec.size() << endl;

	vec.push_back(3);
	cout << vec.capacity() << endl;
	cout << vec.size() << endl;

	vec.push_back(4);
	cout << vec.capacity() << endl;
	cout << vec.size() << endl;
 
		vec.push_back(3);
	cout << vec.capacity() << endl;
	cout << vec.size() << endl;

		vec.push_back(3);
	cout << vec.capacity() << endl;
	cout << vec.size() << endl;
    return EXIT_SUCCESS;
}