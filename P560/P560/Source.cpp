#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>	
using namespace std;
//Prefix sum
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int cum=0; // cumulated sum
//        map<int,int> rec; // prefix sum recorder
//        int cnt = 0; // number of found subarray
//        rec[0]++; // to take into account those subarrays that begin with index 0
//        for(int i=0;i<nums.size();i++){
//            cum += nums[i];
//            cnt += rec[cum-k];
//            rec[cum]++;
//        }
//        return cnt;
//    }
//};
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int count = 0, sum = 0, start= 0;
//		for (int i = 0; i < nums.size(); ++i)
//		{
//			sum = nums[i];
//			if (sum == k)
//				count++;
//			for(int j = i + 1; j < nums.size(); ++j)
//			{
//				sum += nums[j];
//				if (sum == k)
//					count++;
//			}
//		}
//
//		return count;
//    }
//};

int main()
{
	ifstream fin("test.txt");
	string str;
	if (fin.is_open())
		getline(fin, str);

	cout << str << endl;
}