/*
* @Author: linus-young
* @Date:   2014-09-09 12:38:27
* @Last Modified by:   linus-young
* @Last Modified time: 2014-09-09 12:49:00
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 505;
char a[maxn], b[maxn];

int dp[maxn][maxn];
// dp[i][j] 表示的是 前 i 个字符和 前 j 个字符的最小编辑距离，i 和 j 都从 1 开始计数

// --------------------
// | i-1,j-1 | i-1, j |
// --------------------
// | i, j-1  |  i, j  |
// --------------------

int f(int i , int j)
{
    if(a[i - 1] == b[j-1])
        return 0;
    return 1;
}

int mm(int x, int y, int z)
{
    return min(min(x, y), z);

}

int main()
{
    int n;
    cin >> n;
    getchar();

    while(n--) {
        gets(a);
        gets(b);

        int la = strlen(a), lb = strlen(b);

        for(int i = 1; i <= la; ++i)
            dp[i][0] = i;
        for(int i = 1; i <= lb; ++i)
            dp[0][i] = i;

        dp[0][0] = 0;

        for(int i = 1; i <= la; ++i) {
            for(int j = 1; j <= lb; ++j) {
                dp[i][j] = mm(dp[i-1][j] + 1, dp[i][j-1] +1, dp[i-1][j-1] + f(i, j));

            }

        }

        cout << dp[la][lb] << endl;
    }
    return 0;
}