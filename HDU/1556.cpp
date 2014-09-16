// hdu 1556

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 100003;

int bit[maxn];

int lowbit(int x)
{
    return x & (-x);
}


void modify(int p, int delta, int n)
{
    while(p <= n) {
        bit[p] += delta;
        p += lowbit(p);
    }
}

int sum(int p)
{
    int ans = 0;

    for(int i = p; i > 0; i -= lowbit(i))
        ans += bit[i];

    return ans;
}

int main()
{
    int n;
    int a, b;

    while(cin >> n && n) {
        memset(bit, 0, sizeof(bit));

        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a, &b);

            modify(a, 1, n);
            modify(b+1, -1, n);

            cout << "circle " << i << ": \n";
            for(int j = 1; j <= n; ++j)
                cout << bit[j] << ' ';
            cout << endl;

        }

        cout << sum(1);
        for(int i = 2; i <= n; ++i)
            cout << ' ' << sum(i);
        cout << endl;
    }

    return 0;
}