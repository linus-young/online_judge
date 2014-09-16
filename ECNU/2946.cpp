#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10005;

int fa[maxn], num[maxn];


int main()
{
    int t, n;
    scanf("%d", &t);
    for(int cas = 0; cas < t; cas++) {
        int cnt = 0;

        cin >> n;
        for(int i =2; i < (int)sqrt(n*1.0) + 1; i++) {
            if(n % i == 0) {
                fa[cnt] = i;
                num[cnt] = 0;
                while(n % i == 0) {
                    n /= i; num[cnt]++;
                }
                cnt++;
            }
        }

        if(n > 1) {
            fa[cnt] = n;
            num[cnt++] = 1;
        }

        cout << cnt << "\n\n";

        for(int i = 0; i < cnt; ++i) {
            cout << "(" << fa[i] << ',' << num[i] << ')';
        }
        cout << endl;


    }

}