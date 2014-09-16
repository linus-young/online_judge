#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int reverse(int x)
{
    int s = x, r;
    int a[5];
    int cnt = 0;

    while(s) {
        s = x / 10;
        r = x % 10;
        a[cnt++] = r;
        x /= 10;
    }

    int ans = 0;
    for(int i = cnt - 1; i >= 0; --i)
        ans += (int)pow(10.0, i) * a[cnt - i - 1];

    return ans;
}

int main()
{
    int n;
    int a, b;

    cin >> n;
    while(n--) {
        cin >> a >> b;
        if(reverse(a + b)== reverse(a) + reverse(b))
            cout << a + b << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
