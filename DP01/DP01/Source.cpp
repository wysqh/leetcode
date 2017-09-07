#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> tmp;
    NumArray(vector<int> nums) {
        tmp.resize(nums.size()+1);
        tmp[0] = 0;
        int index = 1;
        for_each(nums.begin(), nums.end(), [this, index](int x) mutable{
            tmp[index] = tmp[index-1] + x;
            index++;
        });
    }
    
    int sumRange(int i, int j) {
        
        return tmp[j+1] - tmp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */