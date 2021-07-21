//I am hunting for the golden stag.
#include <cstdio>
#define int long long
int n,m,k,p;
signed main() {
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	if (n == p) { if (k%n) return printf("NO")*0;
	} else if (k/p <= (k%p)/(n-p)+((k%p)%(n-p) ? 1 : 0)) return printf("NO")*0;
	if (k/p > m && m <= (k-p*m)/(n-p)+((k-p*m)%(n-p) ? 1 : 0)) return printf("NO")*0;
	if (k <= m*p) {
		for (int i = 1;i <= p;i++) printf("%lld %lld\n",k/p,m-k/p);
		for (int i = 1;i <= n-p;i++) {
			int cnt = (k%p)/(n-p)+(i <= (k%p)%(n-p));
			printf("%lld %lld\n",cnt,m-cnt);
		}
	} else {
		for (int i = 1;i <= p;i++) printf("%lld 0\n",m);
		for (int i = 1;i <= n-p;i++) {
			int cnt = (k-p*m)/(n-p)+(i <= (k-p*m)%(n-p));
			printf("%lld %lld\n",cnt,m-cnt);
		}
	}
	return 0;
}
