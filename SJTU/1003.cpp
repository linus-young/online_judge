#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 103;

int mat[maxn][maxn];
int fuben[maxn][maxn];
int n;

bool finish(int count, int kang)
{
    if(count + kang == n * n)
        return true;
    return false;
}


void copy()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            fuben[i][j] = mat[i][j];
}

void update(int i, int j)
{
    if(mat[i - 1][j] == 0)
        mat[i - 1][j] = 1;
    if(mat[i + 1][j] == 0)
        mat[i + 1][j] = 1;
    if(mat[i][j - 1] == 0)
        mat[i][j - 1] = 1;
    if(mat[i][j + 1] == 0)
        mat[i][j + 1] = 1;
}


int main(int argc, char const *argv[])
{

    while(cin >> n) {
        int kang = 0;
        int ans = 0;

        memset(mat, 0, sizeof(mat));
        memset(fuben, 0, sizeof(fuben));

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j] == 2)
                    ++kang;
            }
        }

        int flag = 0;

        while(!flag) {
            copy(); // 每次都要在 mat 上更新，然后保存一个副本，在副本上判断主图是否需要更新

            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(fuben[i][j] == 1)
                        update(i, j);
                }
            }

            int count = 0;
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(mat[i][j] == 1)
                        ++count;
                }
            }

            if(finish(count, kang))
                flag = 1;

            ++ans;
        }

        cout << ans << endl;
    }


    return 0;
}