#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	bool operator <(Point x){
			return true;
	}
};

struct compare
{
  bool operator() (const Point& y, const Point& x) const
  {
      return y.x > x.x;
  }
};
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<int, int> slopes;
        unordered_map<Point, int> samepoints;
    }
};