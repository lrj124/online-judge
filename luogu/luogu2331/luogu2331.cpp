/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.01.15:13
*Mail          :  1584634848@qq.com
*Problem       :  luogu2331
************************************************/
#include <algorithm>
#include <cstdio>
using std :: max;
const int maxn = 100 + 10;
int n,m,k,a[maxn],b[maxn],f[maxn][maxn][maxn];
int main() {
// 	freopen("luogu2331.in","r",stdin);
// 	freopen("luogu2331.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if (m == 1) {
		for (int i = 1;i <= n;a[i] += a[i-1],i++) scanf("%d",&a[i]);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= k;j++) {
				f[0][i][j] = f[0][i-1][j];
				for (int l = 1;l <= i;l++) f[0][i][j] = max(f[0][i][j],f[0][l-1][j-1]+a[i]-a[l-1]);
			}
		printf("%d",f[0][n][k]);
	} else {
		for (int i = 1;i <= n;a[i] += a[i-1],b[i] += b[i-1],i++) scanf("%d%d",&a[i],&b[i]);
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				for (int t = 1;t <= k;t++) {
					f[i][j][t] = max(f[i][j-1][t],f[i-1][j][t]);
					for (int l = 1;l <= i;l++) f[i][j][t] = max(f[i][j][t],f[l-1][j][t-1]+a[i]-a[l-1]);
					for (int l = 1;l <= j;l++) f[i][j][t] = max(f[i][j][t],f[i][l-1][t-1]+b[j]-b[l-1]);
					if (i == j) for (int l = 1;l <= i;l++) f[i][j][t] = max(f[i][j][t],f[l-1][l-1][t-1]+a[i]-a[l-1]+b[j]-b[l-1]);
				}
		printf("%d",f[n][n][k]);
	}
	return 0;
}
