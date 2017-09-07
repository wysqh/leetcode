#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <list>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int booms = 0;
		for (auto& p: points)
		{
			unordered_map<double, int> ctr(points.size());
			for (auto& q : points)
				booms += 2 * ctr[hypot(p.first-q.first, p.second-q.second)]++;
		}

		return booms;
    }
};

int main()
{
	allocator<int> alloc;
	int a[] = {3,4,5,2,1,0};
	vector<int> vec(begin(a), end(a));
	list<int> lit(begin(a), end(a));
	iterator<random_access_iterator_tag, int> ds;
	std::list<int>::iterator it;
	
	streambuf *psbuf, *backup;
	ofstream filestr;
	filestr.open("test.txt");

	backup = cout.rdbuf();

	psbuf = filestr.rdbuf();
	cout.rdbuf(psbuf);

	cout << "This is written to the file" << ends;
	
	cout.rdbuf(backup);
	filestr.close();
	
	return 0;
}