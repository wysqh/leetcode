#include <iostream>
#include <algorithm>
#include <queue>
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
	bool a = false;
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

#include <string>
using namespace std;
class Solution
{
public:
	string multiply(string num1, string num2)
	{
		string res(num1.size()+num2.size(), '0');
		
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				int tmp = (res[i+j+1] - '0') + (num1[i]-'0')*(num2[j]-'0')+carry;
				res[i+j+1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			res[i] += carry;
		}

		size_t startpos = res.find_last_not_of("0");
		if (string::npos != startpos)
			return res.substr(startpos);
		long double a;
		return "0";
	}
};





