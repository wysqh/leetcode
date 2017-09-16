#include<stdio.h>
#include<algorithm>
#include<string.h>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
//struct node{
//   int sum;
//   int point;
//}n1[505];
//int main()
//{
//	multiset<int> ds;
//	ds.insert(4);
//	ds.insert(2);
//	ds.insert(2);
//	for (const auto&e: ds)
//		cout << &e << endl;
//   /* int c,n,a[505],b[505],m,k,z,max1,i,j;
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
//    }*/
//}

class Solution {
public:
    string multiply(string num1, string num2) {
		string res(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; i >= 0; --i)
		{
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				int tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				res[i+j+1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			res[i] = carry + '0';
		}
        cout << res << endl;
		size_t startpos = res.find_first_not_of("0");
		if (string::npos != startpos)
			return res.substr(startpos);

		return "0";
    }
};

void combine(vector<vector<char>>& rtvals, vector<char>& container, vector<char> lists)
{
	if (lists.empty())
		rtvals.push_back(container);

	for (int i = 0; i< lists.size(); ++i)
	{
		swap(lists[0], lists[i]);
		container.push_back(lists[0]);
		combine(rtvals, container, vector<char>(lists.begin()+1, lists.end()));
		container.pop_back();
		swap(lists[0], lists[i]);
	}
}

int main()
{
	Solution s;
	vector<char> b;
	for (int i = 0; i <= 2; i++)
		b.push_back('a'+i);

	vector<vector<char>> rt;
	vector<char> container;
	combine(rt, container, b);
	for (const auto& r: rt)
	{
		for (const auto& e: r)
			cout << e << " ";
		cout << endl;
	}

}