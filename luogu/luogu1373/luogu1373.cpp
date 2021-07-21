/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.12.10:16
*Mail          :  1584634848@qq.com
*Problem       :  luogu1373
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n,m,k,a[801][801],f[801][801][17][2];
int main() {
	freopen("luogu1373.in","r",stdin);
	freopen("luogu1373.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k); k++;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) {
			scanf("%d",&a[i][j]);
			f[i][j][a[i][j]%k][0] = 1;
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			for (int t = 0;t <= k;t++) {
				f[i][j][t][0] = (f[i][j][t][0]+f[i-1][j][(t-a[i][j]+k)%k][1])%mod;
				f[i][j][t][0] = (f[i][j][t][0]+f[i][j-1][(t-a[i][j]+k)%k][1])%mod;
				f[i][j][t][1] = (f[i][j][t][1]+f[i-1][j][(t+a[i][j])%k][0])%mod;
				f[i][j][t][1] = (f[i][j][t][1]+f[i][j-1][(t+a[i][j])%k][0])%mod;
			}
	long long ans = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++) ans = (ans+1ll*f[i][j][0][1])%mod;
	printf("%lld\n",ans);
	return 0;
}
