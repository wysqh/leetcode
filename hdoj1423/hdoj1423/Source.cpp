#include<stdio.h>
#include<algorithm>
#include<string.h>
#include <iostream>
#include <set>
using namespace std;
struct node{
   int sum;
   int point;
}n1[505];
int main()
{
	multiset<int> ds;
	ds.insert(4);
	ds.insert(2);
	ds.insert(2);
	for (const auto&e: ds)
		cout << &e << endl;
   /* int c,n,a[505],b[505],m,k,z,max1,i,j;
    scanf("%d",&c);
    while(c--)
    {
        memset(n1,0,sizeof(n1));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        scanf("%d",&b[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i]==b[j])
                {
                    n1[i].sum=1;
                    n1[i].point=j;
                    for(k=i-1;k>=0;k--)
                    {
                        if(a[k]<a[i]&&n1[k].point<n1[i].point)
                         n1[i].sum=max(n1[i].sum,1+n1[k].sum);
                    }
                }
            }
        }
        for(i=0,max1=-1;i<n;i++)
            if(max1<n1[i].sum)
            max1=n1[i].sum;
        printf("%d\n",max1);
        if(c)
            putchar(10);
    }*/
}