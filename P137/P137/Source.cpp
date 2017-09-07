#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> maps;
        
        for (const auto& e: nums) {
            maps[e]++;
        }
        
        for (const auto&e : maps){
            if (e.second == 1) {
				return e.first;
            }
        }
        
        return -1;
    }
};