/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.27.20:59
*Mail          :  1584634848@qq.com
*Problem       :  luogu2401
************************************************/
#include <cstdio>
const int mod = 2015;
const int maxn = 1000 + 10;
int n,k,f[maxn][maxn];
int main() {
	//freopen("luogu2401.in","r",stdin);
	//freopen("luogu2401.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[1][0] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 0;j <= i;j++) {
			f[i][j] = f[i-1][j]*(j+1)%mod;
			if (j) f[i][j] += f[i-1][j-1]*(i-j)%mod;
		}
	printf("%d",f[n][k]%mod);
	return 0;
}
