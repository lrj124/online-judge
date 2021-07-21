/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.14.20:05
*Mail          :  1584634848@qq.com
*Problem       :  UVa11806
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int T,n,m,k,c[501][501],ans,Case;
int main() {
	freopen("UVa11806.in","r",stdin);
	freopen("UVa11806.out","w",stdout);
	c[0][0] = 1;
	for (int i = 1;i <= 500;i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1;j < i;j++) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (scanf("%d",&T);T--;) {
		scanf("%d%d%d",&n,&m,&k); ans = 0;
		for (int sta = 0,cnt,N,M;sta < (1<<4);sta++) {
			cnt = 0; N = n; M = m;
			if (sta&(1<<0)) { N--; cnt++; }
			if (sta&(1<<1)) { N--; cnt++; }
			if (sta&(1<<2)) { M--; cnt++; }
			if (sta&(1<<3)) { M--; cnt++; }
			if (cnt&1) ans = (ans-c[N*M][k]+mod)%mod;
			else ans = (ans+c[N*M][k])%mod;
		}
		printf("Case %d: %d\n",++Case,ans);
	}
	return 0;
}
