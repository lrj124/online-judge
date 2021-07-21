/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.25.17:29
*Mail          :  1584634848@qq.com
*Problem       :  luogu2051
************************************************/
#include <bits/stdc++.h>
using namespace std;
inline int calc(int x) { return x*(x-1)/2; }
const int maxn = 100 + 10;
const int mod = 9999973;
int n,m,f[maxn][maxn][maxn],ans;
int main() {
	freopen("luogu2051.in","r",stdin);
	freopen("luogu2051.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0][0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= m;j++)
			for (int k = 0;k <= m-j;k++)
				if (f[i][j][k]) {
					f[i+1][j][k] = (f[i+1][j][k]+f[i][j][k])%mod;
					if (m-j-k >= 1) f[i+1][j+1][k] = (1ll*f[i+1][j+1][k]+1ll*f[i][j][k]*(m-j-k))%mod;
					if (j >= 1) f[i+1][j-1][k+1] = (1ll*f[i+1][j-1][k+1]+1ll*f[i][j][k]*j)%mod;
					if (m-j-k >= 2) f[i+1][j+2][k] = (1ll*f[i+1][j+2][k]+1ll*f[i][j][k]*calc(m-j-k))%mod;
					if (m-j-k >= 1 && j >= 1) f[i+1][j][k+1] = (1ll*f[i+1][j][k+1]+1ll*f[i][j][k]*(m-j-k)*j)%mod;
					if (j >= 2) f[i+1][j-2][k+2] = (1ll*f[i+1][j-2][k+2]+1ll*f[i][j][k]*calc(j))%mod;
				}
	long long ans = 0;
	for (int i = 0;i <= m;i++)
		for (int j = 0;j <= m-i;j++) ans = (ans+f[n][i][j])%mod;
	printf("%lld",ans);
	return 0;
}
