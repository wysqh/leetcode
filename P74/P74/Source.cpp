#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size())
            return false;
        
        for (int i = 0; i < matrix.size(); i++)
        {
            if (target < matrix[i][0])
                return false;
                
            if (target > matrix[i][matrix[0].size()-1] && i == matrix.size() - 1)
                return false;
                
            for (auto e: matrix[i])
                if (e == target)
                    return true;
        }
        
        return false;
    }
};