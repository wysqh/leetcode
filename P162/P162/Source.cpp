#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;

		if (nums[0] > nums[1])
			return 0;
		if (nums.back() > nums[nums.size()-2])
			return nums.size() - 1;

		for (int i = 1; i < nums.size() - 1; ++i)
			if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
				return i;

		return -1;
    }
};
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//struct node{
//   int sum;
//   int point;
//}n1[505];
//int main()
//{
//    int c,n,a[505],b[505],m,k,z,max1,i,j;
//    scanf("%d",&c);
//    while(c--)
//    {
//        memset(n1,0,sizeof(n1));
//        scanf("%d",&n);
//        for(i=0;i<n;i++)
//        scanf("%d",&a[i]);
//        scanf("%d",&m);
//        for(i=0;i<m;i++)
//        scanf("%d",&b[i]);
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//            {
//                if(a[i]==b[j])
//                {
//                    n1[i].sum=1;
//                    n1[i].point=j;
//                    for(k=i-1;k>=0;k--)
//                    {
//                        if(a[k]<a[i]&&n1[k].point<n1[i].point)
//                         n1[i].sum=max(n1[i].sum,1+n1[k].sum);
//                    }
//                }
//            }
//        }
//        for(i=0,max1=-1;i<n;i++)
//            if(max1<n1[i].sum)
//            max1=n1[i].sum;
//        printf("%d\n",max1);
//        if(c)
//            putchar(10);
//    }
//}