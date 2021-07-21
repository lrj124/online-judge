/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.06.20:53
*Mail          :  1584634848@qq.com
*Problem       :  UVA11582
************************************************/
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll T,a,b,n,f[1000001],Mod;
inline ll power(ll x,ll y,ll mod) {
	ll ans = 1; x %= mod;
	for (;y;y >>= 1,x = x*x%mod) if (y&1) ans = ans*x%mod;
	return ans;
}
int main() {
	freopen("UVA11582.in","r",stdin);
	freopen("UVA11582.out","w",stdout);
	for (scanf("%llu",&T);T--;) {
		scanf("%llu%llu%llu",&a,&b,&n);
		Mod = n*n;
		f[1] = 1%n;
		for (ll i = 2;i <= Mod;i++) {
			f[i] = (f[i-1]+f[i-2])%n;
			if (f[i] == f[1] && !f[i-1]) {
				Mod = i-1;
				break;
			}
		}
		printf("%llu\n",f[power(a,b,Mod)]);
	}
	cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
