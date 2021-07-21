/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.12.22:03
*Mail          :  1584634848@qq.com
*Problem       :  UVa1638
************************************************/
#include <cstdio>
long long f[21][21][21];
int T,n,l,r;
int main() {
	freopen("UVa1638.in","r",stdin);
	freopen("UVa1638.out","w",stdout);
	f[1][1][1] = 1;
	for (int i = 2;i <= 20;i++)
		for (int j = 1;j <= i;j++)
			for (int k = 1;k <= i;k++) f[i][j][k] += f[i-1][j-1][k]+f[i-1][j][k-1]+f[i-1][j][k]*(i-2);
	for (scanf("%d",&T);T--;printf("%lld\n",f[n][l][r])) scanf("%d%d%d",&n,&l,&r);
	return 0;
}
