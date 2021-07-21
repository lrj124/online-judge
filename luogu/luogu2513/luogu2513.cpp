/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.25.21:40
*Mail          :  1584634848@qq.com
*Problem       :  luogu2513
************************************************/
#include <cstdio>
const int maxn = 1000 + 10;
const int mod = 10000;
int n,k,f[1010][1010],pre[1010];
int main() {
	//freopen("luogu2513.in","r",stdin);
	//freopen("luogu2513.out","w",stdout);
	scanf("%d%d",&n,&k); f[1][0] = 1;
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j <= k+1;j++) pre[j] = (pre[j-1]+f[i-1][j-1])%mod;
		for (int j = 0;j <= k;j++) f[i][j] = (pre[j+1]-pre[j-i+1 > 0 ? j-i+1 : 0]+mod)%mod;
	}
	printf("%d",f[n][k]);
	return 0;
}
