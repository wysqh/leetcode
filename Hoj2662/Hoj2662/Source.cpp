#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//Code from: http://blog.csdn.net/wangjianbing1998/article/details/52168249
#define LL long long
LL dp[82][22][1<<6],mark[1<<6],zt,ans;
int n,m,k;
int num(LL x)//返回一个状态的值对应的1的个数，就是这第X行里所用的旗子的个数
{
    int sum=0;
    while(x)
    {
        if(x&1)sum++;
        x=x>>1;
    }
    return sum;
}
bool judge_row(int x)//这里就判断每一行里边是否满足互不相邻
{
    return (!(x&(x<<1)));
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        zt=0;
        memset(dp,0,sizeof dp);
        memset(mark,0,sizeof mark);
        if(n<m)//这里是保证n>=m，使用异或运算减少时间。
        {
        n=n^m;
        m=n^m;
        n=n^m;
        }
//        cout<<"******************"<<endl<<n<<m<<endl;
        for(LL i=0;i<(1<<m);i++)//初始化第一行
        {
            if(judge_row(i))
            {
                dp[1][num(i)][zt]=1;
                mark[zt++]=i;
            }
        }
        for(int i=2;i<=n;i++)//分别将2~n行都壮压
            for(int j=0;j<=k;j++)
            for(LL x=0;x<zt;x++)
            for(LL y=0;y<zt;y++)
            {
//                LL temp=num(mark[x]);
                if(((mark[x]&mark[y])==0)&&j>=num(mark[x]))//这里是判断上下两行是不是合法和剩下的旗子都不够用来放在第x行里边
                {
                    dp[i][j][x]+=dp[i-1][j-num(mark[x])][y];//将上一行已经得到的结果和这一行的结果加起来就是这前i行的总方案数
                }
            }
        ans=0;
        for(LL i=0;i<zt;i++)//对于通过不同状态扫到了末尾的那些方案数加起来，就是最终答案
        ans+=dp[n][k][i];
            printf("%lld\n",ans);
    }
}

