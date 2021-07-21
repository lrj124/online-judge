//I am hunting for the golden stag.
#include <cstdio>
#define X(i) (pre[i])
#define Y(i) (f[i]+s[i])
#define int long long
const int maxn = 1e6 + 10;
int n,h,t,q[maxn],s[maxn],x[maxn],f[maxn],c[maxn],pre[maxn];
inline long double slope(int i,int j) { return (long double)(Y(i)-Y(j))/(X(i)-X(j)); }
signed main() {
	freopen("luogu2120.in","r",stdin);
	freopen("luogu2120.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1,p;i <= n;i++) {
		scanf("%lld%lld%lld",&x[i],&p,&c[i]);
		pre[i] = pre[i-1]+p;
		s[i] = s[i-1]+p*x[i];
	}
	for (int i = 1;i <= n;i++) {
		for (;h < t && slope(q[h],q[h+1]) < x[i];h++);
		f[i] = f[q[h]]+x[i]*(pre[i]-pre[q[h]])-(s[i]-s[q[h]])+c[i];
		for (;h < t && slope(q[t],q[t-1]) > slope(q[t-1],i);t--);
		q[++t] = i;
	}
	printf("%lld",f[n]);
	return 0;
}
