/*
* @Author: linus-young
* @Date:   2014-09-07 11:15:51
* @Last Modified by:   linus-young
* @Last Modified time: 2014-09-07 18:28:10
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int f[1005];

int h, w, t;


int nextdir(int x, int y, int dir)
{
    if(x == 1) {
        if(y == 1 && (dir == 0 || dir == 3))
            dir = 1;
        else if(y == w && (dir == 0 || dir == 1))
            dir = 2;
        else if(y > 1 && y < w && dir == 0)
            dir = 1;
    }
    else if(x > 1 && x < h) {
        if(y == 1 && dir == 3)
            dir = 0;
        else if(y == w && dir == 1)
            dir = 2;
    }
    else if(x == h) {
        if(y == 1 && (dir == 2 || dir == 3))
            dir = 0;
        else if(y == w && (dir == 1 || dir == 2))
            dir = 3;
    }

    return dir;
}


int main()
{

    char s[105];

    f[0] = 0; f[1] = 1;
    for(int i = 2; i < 1002; ++i)
        f[i] = (f[i - 1] % 4 + f[i - 2] % 4) % 4;

    while(cin >> h >> w >> t) {
        //getchar();
        for(int i = 1; i <= h; ++i) {
            scanf("%s", s);
            for(int j = 1; j <= w; ++j) {

                if(s[j - 1] == '.')
                    a[i][j] = 0;
                else
                    a[i][j] = s[j - 1] - 48;
            }
        }

        int life = 0;
        int px = 1, py = 1, nextx, nexty;
        int dir, ndir;


        for(int i = 0; i <= t; ++i) {
            life += a[px][py];

            dir = f[i];
            ndir = nextdir(px, py, dir);

            if(ndir == 0) {
                nextx = px - 1; nexty = py;
            }
            else if(ndir == 1) {
                nextx = px; nexty = py + 1;
            }
            else if(ndir == 2){
                nextx = px + 1; nexty = py;
            }
            else if(ndir == 3) {
                nextx = px; nexty = py - 1;
            }

            px = nextx;
            py = nexty;

        }

        cout << life << endl;
    }
    return 0;
}