/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.13.16:11
*Mail          :  1584634848@qq.com
*Problem       :  UVa104
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100;
int n,ans[maxn][maxn][maxn];
double dis[maxn][maxn][maxn];
inline void print(int now,int nex,int dep) {
	if (!dep) printf("%d",now);
	else {
		print(now,ans[now][nex][dep],dep-1);
		printf(" %d",nex);
	}
}
int main() {
	freopen("UVa104.in","r",stdin);
	freopen("UVa104.out","w",stdout);
	for (;scanf("%d",&n) ^ EOF;puts("")) {
		memset(dis,0,sizeof(dis));
		memset(ans,0,sizeof(ans));
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i ^ j) {
					ans[i][j][1] = i;
					scanf("%lf",&dis[i][j][1]);
				}
		bool flag = false;
		for (int t = 2;t <= n;t++) {
			for (int k = 1;k <= n;k++)
				for (int i = 1;i <= n;i++)
					for (int j = 1;j <= n;j++)
						if (dis[i][j][t] < dis[i][k][t-1]*dis[k][j][1]) {
							dis[i][j][t] = dis[i][k][t-1]*dis[k][j][1];
							ans[i][j][t] = k;
						}
			if (flag) break;
			for (int i = 1;i <= n;i++)
				if (dis[i][i][t] > 1.01) {
					print(i,i,t);
					flag = true;
					break;
				}
		}
		if (!flag) printf("no arbitrage sequence exists");
	}
	return 0;
}
