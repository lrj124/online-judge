/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.05.21:54
*Mail          :  1584634848@qq.com
*Problem       :  luogu4980
************************************************/
#include <cstdio>
#define int ll
using ll = long long;
const int mod = (int)1e9 + 7;
int t,n,ans;
inline int power(int x,int y) {
	int res = 1;
	for (;y;y >>= 1,x = 1ll*x*x%mod) if (y&1) res = 1ll*res*x%mod;
	return res;
}
inline int phi(int x) {
	int res = 1;
	for (int i = 2;i*i <= x;i++)
		if (!(x%i)) for (x /= i,res = 1ll*res*(i-1)%mod;!(x%i);x /= i,res = 1ll*res*i%mod);
	if (x > 1) res = 1ll*res*(x-1)%mod;
	return res;
}
signed main() {
	freopen("luogu4980.in","r",stdin);
	freopen("luogu4980.out","w",stdout);
	for (scanf("%lld",&t);t--;ans = 0) {
		scanf("%lld",&n);
		for (int i = 1;i*i <= n;i++)
			if (!(n%i)) {
				ans = (ans+1ll*phi(i)*power(n,n/i-1)%mod)%mod;
				if (i*i ^ n) ans = (ans+phi(n/i)*power(n,i-1))%mod;
			}
		printf("%lld\n",ans);
	}
	return 0;
}
