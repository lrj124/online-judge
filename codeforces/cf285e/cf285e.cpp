#include <cstdio>
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1000 + 10;
ll n,m,f[maxn][maxn][2][2],g[maxn],fac[maxn] = { 1 };
inline ll power(ll x,ll y) {
	ll ans = 1;
	for (;y;y >>= 1,x = x*x%mod) if (y & 1) ans = ans*x%mod;
	return ans;
}
inline ll C(int n,int m) {
	return fac[n]*power(fac[m],mod-2)%mod*power(fac[n-m],mod-2)%mod;
}
int main() {
	freopen("cf285e.in","r",stdin);
	freopen("cf285e.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++) fac[i] = fac[i-1]*i%mod;
	f[1][0][0][0] = f[1][1][0][1] = 1;
	for (ll i = 2;i <= n;i++) {
		f[i][0][0][0] = f[i-1][0][0][0]+f[i-1][0][1][0];
		f[i][0][1][0] = f[i-1][0][0][1]+f[i-1][0][1][1];
		for (ll j = 1;j <= i;j++) {
			f[i][j][0][0] = (f[i-1][j-1][0][0]+f[i-1][j][0][0]+f[i-1][j][1][0])%mod;
			f[i][j][0][1] = (f[i-1][j-1][0][0]+f[i-1][j-1][1][0])%mod;
			f[i][j][1][0] = (f[i-1][j-1][0][1]+f[i-1][j][0][1]+f[i-1][j][1][1])%mod;
			f[i][j][1][1] = (f[i-1][j-1][0][1]+f[i-1][j-1][1][1])%mod;
		}
	}
	ll ans = 0;
	for (ll i = m;i <= n;i++) (ans += power(-1,i-m)*C(i,m)%mod*(f[n][i][0][0]+f[n][i][1][0])%mod*fac[n-i]%mod+mod) %= mod;
	printf("%lld",ans);
	return 0;
}
