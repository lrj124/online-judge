//2021.07.19 08:57 by lrj124.
#include <cstdio>
typedef long long ll;
const int mod = 1e9 + 7;
inline ll gcd(ll x,ll y) { return y ? gcd(y,x%y) : x; }
inline ll lcm(ll x,ll y) { return x/gcd(x,y)*y; }
ll t,n,ans;
int main() {
	for (scanf("%lld",&t);t--;ans = 0) {
		scanf("%lld",&n);
		ll num = 1;
		for (int i = 2;i <= 50;i++) {
			(ans += i*(n/num-n/lcm(num,i))%mod) %= mod;
			num = lcm(num,i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
