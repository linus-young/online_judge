#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
    int t;
    int a, b, c, d;

    cin >> t;
    for(int cas = 0; cas < t; cas++) {
        cin >> a >> b >> c >> d;

        cout << "case #"<<cas<<":\n";

        for(int i = 1; i <= 21252; ++i) {
            if((i + d - a)%23 == 0 && (i + d - b)%28 == 0 && (i + d - c)%33 == 0) {
                cout <<"the next triple peak occurs in "<< i <<" days.\n";
                break;
            }

        }

    }
    return 0;

}