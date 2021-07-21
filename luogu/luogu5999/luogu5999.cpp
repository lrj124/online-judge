/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.19.14:41
*Mail          :  1584634848@qq.com
*Problem       :  luogu5999
************************************************/
#include <cstdio>
const int maxn = 2e3 + 10;
const int mod = 1e9 + 7;
int n,s,t,f[maxn][maxn];
int main() {
	freopen("luogu5999.in","r",stdin);
	freopen("luogu5999.out","w",stdout);
	scanf("%d%d%d",&n,&s,&t);
	f[1][1] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j <= i;j++)
			if (i ^ s && i ^ t) f[i][j] = (1ll*f[i-1][j-1]*(j-(i>s)-(i>t))+1ll*f[i-1][j+1]*j)%mod;
			else f[i][j] = (f[i-1][j]+f[i-1][j-1])%mod;
	printf("%d",f[n][1]);
	return 0;
}
