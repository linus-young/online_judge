#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int cost[maxn][maxn];

const int mindis = 9999999;
int lowcost[maxn];
int closet[maxn];


// 2573.cpp
int prim(int n)
{
	int ans = 0;
	int minn;

	for(int i = 1; i <= n; ++i) {
		closet[i] = 1;
		lowcost[i] = cost[1][i];
	}

	int k;
	for(int i = 1; i < n; ++i) {
		minn = mindis;
		
		for(int j = 1; j <= n; ++j) {
			if(lowcost[j] != 0 && lowcost[j] < minn) {
				minn = lowcost[j];
				k = j;
			}
		}

		//printf("%3d %3d %5d,  ", closet[k], k, minn);

		ans += minn;

		lowcost[k] = 0;

		for(int j = 1; j <= n; ++j) {
			if(lowcost[j]!= 0 && cost[k][j] < lowcost[j]) {
				lowcost[j] = cost[k][j];
				closet[j] = k;
			}	
		}
	}

	return ans;

}

int main()
{
	int n, m;
	int a, b;
	while(cin >> n >> m) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(i == j)
					cost[i][i] = 0;
				else
					cost[i][j] = mindis; // 这句也不能落下！！！
			}
		}
		
		// 两次 wa 的原因是 cost 数组初始化有问题！！
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			scanf("%d", &cost[a][b]);
			cost[b][a] = cost[a][b]; // 这句千万别忘记！！！
		}	

		cout << prim(n) << endl;

	}
	
	return 0;
}