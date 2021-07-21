/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.15.20:48
*Mail          :  1584634848@qq.com
*Problem       :  cf505c
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 3e4;
const int inf = 1e9;
const int D = 400;
int n,d,ans,a[maxn+10],f[maxn+10][D<<1|1];
int main() {
	freopen("cf505c.in","r",stdin);
	freopen("cf505c.out","w",stdout);
	scanf("%d%d",&n,&d);
	for (int i = 1,x;i <= n;i++) scanf("%d",&x),a[x]++;
	for (int i = 0;i <= maxn;i++)
		for (int j = -D;j <= D;j++) f[i][j+D] = -inf;
	f[d][D] = a[0]+a[d];
	ans = f[d][D];
	for (int i = d;i <= maxn;i++)
		for (int j = -D;j <= D;j++) {
			if (f[i][j+D] ^ -inf) for (int k = -1;k <= 1;k++) {
				int to = i+d+j+k;
				if (j+k >= -D && j+k <= D && to > i && to <= maxn) {
					f[to][j+k+D] = max(f[to][j+k+D],f[i][j+D]+a[to]);
					ans = max(ans,f[to][j+k+D]);
				}
			}
		}
	printf("%d",ans);
	return 0;
}
