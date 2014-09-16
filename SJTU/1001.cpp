#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int height, dengzi, n;
    int x;

    while(cin >> height >> dengzi >> n) {
        int ans = 0;
        int limit = height + dengzi;

        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if(x <= limit)
                ++ans;
        }

        cout << ans << endl;
    }

    return 0;
}