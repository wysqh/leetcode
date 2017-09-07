#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int count = 0;
		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (flowerbed[i] == 1)
				continue;

			if (i == 0)
			{
				if (flowerbed[i+1] != 1)
				{
					count++;
					flowerbed[i] = 1;
				}
			}
			else if (i == flowerbed.size() - 1)
			{
				if (flowerbed[i-1] != 1)
				{
					flowerbed[i] = 1;
					count++;
				}
			}
			else
			{
				if (flowerbed[i+1] != 1 && flowerbed[i-1] != 1)
				{
					count++;
					flowerbed[i] = 1;
				}
			}
		}

		return count >= n;
    }
};