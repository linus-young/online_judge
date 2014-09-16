#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// 版本3， 动态构造二维数组

// 坐标轴如下图示：

//  o--------------------> y
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  |
//  ﹀
//  x

int lowbit(int x)
{
    return x & (-x);
}


void init(int **mat, int **bit, int L, int W)
// bit[x][y] = sum(mat[i][j]), 其中 x-lowbit(x) << i << x, y-lowbit(y) << j << y;
{


    // memset(bit, 0, sizeof(bit));

    for(int x = 1; x <= L; ++x)      // row, 行对应 x 轴(纵向)， 列对应 y 轴（横向）
        for(int y = 1; y <= W; ++y)  // column
            for(int i = x - lowbit(x) + 1; i <= x; ++i)
                for(int j = y - lowbit(y) + 1; j <= y; ++j)
                    bit[x][y] += mat[i][j];

}

int sum(int **bit, int x, int y) //  从(1,1)到矩形右下角的 bit 之和，即 sum(bit[i][j]), i 从 1 到 x, j 从 1 到 y
{
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        for(int j = y; j > 0; j -= lowbit(j)) {
            ans += bit[i][j];
        }
    }

    return ans;
}

int get_rectangle_sum(int **bit, int xmin, int ymin, int xmax, int ymax)
// 类似容斥原理，求给定矩形内的所有数之和
// 矩形由 左上顶点 (xmin, ymin) 和 右下顶点 (xmax, ymax) 确定
{
    return sum(bit, xmax, ymax) - sum(bit, xmax, ymin - 1) - sum(bit, xmin - 1, ymax) + sum(bit, xmin - 1, ymin - 1);
}


int main(int argc, char const *argv[])
{
    int L, W;
    int a, b;

    while(cin >> L >> W) {

        int **mat = new int *[L + 1];
        for(int i = 1; i <= L; ++i)
            mat[i] = new int [W + 1];

        int **bit = new int *[L + 1];
        for(int i = 1; i <= L; ++i)
            bit[i] = new int [W + 1];

        for(int i = 1; i <= L; ++i) {
            for(int j = 1; j <= W; ++j)
                scanf("%d", &mat[i][j]);
        }

        cin >> a >> b;

        init(mat, bit, L, W);

        int ans = 0;

        // int xmin = 1, ymin = 1, xmax = 1, ymax = 1;

        for(int i = 1; i <= L - a + 1; ++i) {      // 行对应的是 x
            for(int j = 1; j <= W - b + 1; ++j) {  // 列对应的是 y
                int aa = i + a - 1;
                int bb = j + b - 1;
                int tmp = get_rectangle_sum(bit, i, j, aa, bb);
                if(ans < tmp) {
                    ans = tmp;
                    // 记录构成最大和的矩形
                    // xmin = i; ymin = j;
                    // xmax = aa; ymax = bb;
                }
            }
        }

        cout << ans << endl;
        // 输出构成最大和的所有元素, 转置输出
        // for(int j = ymin; j <= ymax; ++j)
        //     for(int i = xmin; i <= xmax; ++i)
        //         cout << mat[i][j] << ((i == ymax) ? '\n' : ' ');
    }

    return 0;
}