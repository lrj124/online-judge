/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.01.21:46
*Mail          :  1584634848@qq.com
*Problem       :  luogu2467
************************************************/
#include <cstdio>
int f[2][4201],n,p,ans;
int main() {
	freopen("luogu2467.in","r",stdin);
	freopen("luogu2467.out","w",stdout);
	scanf("%d%d",&n,&p);
	f[0][2] = 1;
	for (int i = 3;i <= n;i++)
		for (int j = 2;j <= i;j++) f[i&1][j] = (1ll*f[i&1][j-1]+1ll*f[i-1&1][i-j+1])%p;
	for (int i = 2;i <= n;i++) ans = (ans+f[n&1][i])%p;
	printf("%d",(ans<<1)%p);
	return 0;
}
