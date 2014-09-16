#include <iostream>
#include <cstdio>

using namespace std;

// 版本四： 在输入的时候就用一个数组维护 大矩形(指从左上角(1, 1)到 右下角(x, y)构成的矩形) 内的元素和，然后还是容斥原理
// 时间 : 1180ms, 85000 kb
// 居然比版本一 快了近一倍
// 不该把题目想复杂了，不需要树状数组的其实==

int ** create_two_dimen_array(int a, int b)
{
    int **arr = new int *[a + 1];
    for(int i = 0; i <= a; ++i)
        arr[i] = new int [b + 1];

    return arr;
}

int get_rectangle_sum(int **sum, int xmin, int ymin, int xmax, int ymax)
{
    return sum[xmax][ymax] - sum[xmax][ymin - 1] - sum[xmin - 1][ymax] + sum[xmin - 1][ymin - 1];
}

int main()
{
    int L, W;
    int a, b;

    while(cin >> L >> W) {

        int **mat = create_two_dimen_array(L, W); // 原矩阵
        int **sum = create_two_dimen_array(L, W); // sum[i][j] 表示从 左上角[1][1] 到 右下角[i][j] 的所有元素之和
        int x;


        for(int i = 1; i <= L; ++i) {
            for(int j = 1; j <= W; ++j) {
                scanf("%d", &x);

                if(i == 1 && j == 1)
                    sum[i][j] = x;
                else if(i == 1 && j > 1)
                    sum[i][j] = sum[i][j - 1] + x;
                else if(j == 1 && i > 1)
                    sum[i][j] = sum[i - 1][j] + x;
                else
                    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + x - sum[i - 1][j - 1];
            }
        }

        cin >> a >> b;

        int ans = 0;

        for(int i = 1; i <= L - a + 1; ++i) {
            for(int j = 1; j <= W - b + 1; ++j) {
                    int tmp = get_rectangle_sum(sum, i, j, i + a - 1, j + b - 1);
                    if(tmp > ans)
                        ans = tmp;
            }
        }

        cout << ans << endl;

    }

    return 0;
}