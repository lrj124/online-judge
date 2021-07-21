/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.12.16:29
*Mail          :  1584634848@qq.com
*Problem       :  poj3311
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10 + 5;
int n,dis[maxn][maxn],f[1<<maxn][maxn];
int main() {
	freopen("poj3311.in","r",stdin);
	freopen("poj3311.out","w",stdout);
	for (;scanf("%d",&n), n;) {
		for (int i = 0;i <= n;i++)
			for (int j = 0;j <= n;j++) scanf("%d",&dis[i][j]);
		for (int k = 0;k <= n;k++)
			for (int i = 0;i <= n;i++)
				for (int j = 0;j <= n;j++)
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		memset(f,10,sizeof f);
		f[(1<<(n+1))-1][0] = 0;
		for (int sta = (1<<(n+1))-1;~sta;sta--)
			for (int i = 0;i <= n;i++)
				if (sta&(1<<i) || (!sta && !i)) for (int k = 0;k <= n;k++)
					if (!(sta&(1<<k))) f[sta][i] = min(f[sta][i],f[sta^(1<<k)][k]+dis[i][k]);
		printf("%d\n",f[0][0]);
	}
	return 0;
}
