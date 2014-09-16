#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1005;

int BIT[maxn];

int lowbit(int x)
{
    return x & (-x);
}


void build(int A[], int n)
{
    for(int i = 1; i <= n; ++i) {
        BIT[i] = A[i];

        for(int j = i - 1; j > i - lowbit(i); j -= lowbit(j))
            BIT[i] += BIT[j];
    }
}

int sum(int A[], int k)
{
    int ans = 0;
    for(int i = k; i > 0; i -= lowbit(i))
        ans += BIT[i];

    return ans;
}

int main(int argc, char const *argv[])
{

    int A[] = {0, 1, 2, 3, 4};

    build(A, 4);

    for(int i = 1; i <= 4; ++i)
        cout << BIT[i] << ' ';
    cout << endl;

    for(int i = 1; i <= 4; ++i)
        cout << sum(A, i) << ' ';
    cout << endl;

    return 0;
}