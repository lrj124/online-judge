//I am hunting for the golden stag.
#include <cstdio>
using ll = long long;
inline ll solve(int n) {
	ll ans = 0;
	for (ll i = 1,j;i <= n;i = j+1) {
		j = n/(n/i);
		ans += (i+j)*(j-i+1)/2*(n/i);
	}
	return ans;
}
int main() {
//	freopen("luogu2424_new.in","r",stdin);
//	freopen("luogu2424_new.out","w",stdout);
	ll a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",solve(b)-solve(a-1));
	return 0;
}
