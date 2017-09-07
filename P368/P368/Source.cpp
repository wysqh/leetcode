#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        
        int m = 0;
        int mi = 0;
        
        for(int i = 0; i < nums.size(); ++i) // if extending by larger elements
        {
            for(int j = i; j >=0; --j) // if extending by larger elements
            {
                // check every a[j] that is larger than a[i]
                if(nums[i] % nums[j] == 0 && T[i] < 1 + T[j])
                {
                    // if a[j] mod a[i] == 0, it means T[j] can form a larger subset by putting a[i] into T[j]
                    T[i] = 1 + T[j];
                    parent[i] = j;
                    
                    if(T[i] > m)
                    {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }
        
        vector<int> ret;
        
        for(int i = 0; i < m; ++i)
        {
            ret.push_back(nums[mi]);
            mi = parent[mi];
        }

        // sort(ret.begin(), ret.end()); // if we go by extending larger ends, the largest "answer" element will come first since the candidate element we observe will become larger and larger as i increases in the outermost "for" loop above.
       // alternatively, we can sort nums in decreasing order obviously. 
        
        return ret;
    }
};