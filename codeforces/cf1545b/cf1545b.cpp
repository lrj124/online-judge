//2021.07.18 13:33 by lrj124.
#include <cstdio>
const int mod = 998244353;
const int maxn = 1e5 + 10;
int t,n,a,b,las,fac[maxn] = { 1 };
inline int power(int x,int y) {
	int ans = 1;
	for (;y;y >>= 1,x = 1ll*x*x%mod) if (y & 1) ans = 1ll*ans*x%mod;
	return ans;
}
inline int c(int n,int m) { return 1ll*fac[n]*power(1ll*fac[m]*fac[n-m]%mod,mod-2)%mod; }
int main() {
//	freopen("halma.in","r",stdin);
//	freopen("halma.out","w",stdout);
	for (int i = 1;i < maxn;i++) fac[i] = 1ll*fac[i-1]*i%mod;
	for (scanf("%d",&t);t--;las = a = b = 0) {
		scanf("%d",&n);
		for (int i = 1,x;i <= n;i++) {
			scanf("%1d",&x);
			if (x && las) a += (las = 0)+1;
			else las = (!x ? b++ : 0)*0+x;
		}
		printf("%d\n",c(a+b,a));
	}
	return 0;
}
