#include <iostream>
#include <algorithm>
using namespace std;

//Mondriaan's Dream

#define ll long long
ll dp[12][(1 << 12)];
int h, w;

bool ok(int t)
{
    int cnt = 0;
    for(int i = 0; i < w; i++)
    {
        if(t & 1) 
        {
            if(cnt & 1) //判断相邻两个1之间0的个数
                return false;
        }
        else
            cnt++;
        t >>= 1; 
    }
    if(cnt & 1) //判断最后一个1左边0的个数
        return false;
    return true;
}

int main()
{
    while(scanf("%d %d", &h, &w) != EOF && (w + h))
    {
        if((h * w) & 1) //面积为奇数不可能拼成，因为一个单位面积就为偶数了
        {
            printf("0\n");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= h; i++)
            for(int j = 0; j < (1 << w); j++)
                for(int k = 0; k < (1 << w); k++)
                    if(((k & j) == 0) && ok(k ^ j))
                        dp[i][j] += dp[i - 1][k];
        printf("%lld\n", dp[h][0]);
    }
}