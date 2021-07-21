#include <cstdio>
using ll = long long;
ll n,p,d,w;
int main() {
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	for (ll a = 0;a < w && d*a <= p;a++) if (!((p-d*a)%w) && (p-d*a)/w+a <= n) return printf("%lld %lld %lld",(p-d*a)/w,a,n-(p-d*a)/w-a)*0;
	printf("-1");
	return 0;
}
