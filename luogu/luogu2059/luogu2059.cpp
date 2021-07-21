/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.27.11:23
*Mail          :  1584634848@qq.com
*Problem       :  luogu2059
************************************************/
#include <cstdio>
const int maxn = 50 + 10;
double f[maxn][maxn];
int n,m,a[maxn];
int main() {
	freopen("luogu2059.in","r",stdin);
	freopen("luogu2059.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++) scanf("%d",&a[i]);
	f[1][1] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j <= i;j++)
			for (int k = 1;k <= m;k++) {
				if ((a[k]%i ? a[k]%i : i) > j) f[i][j] += f[i-1][j+i-(a[k]%i ? a[k]%i : i)]/m;
				if ((a[k]%i ? a[k]%i : i) < j) f[i][j] += f[i-1][j-(a[k]%i ? a[k]%i : i)]/m;
			}
	for (int i = 1;i <= n;i++) printf("%.2f%% ",f[n][i]*100);
	return 0;
}
