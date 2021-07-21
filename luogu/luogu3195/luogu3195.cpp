//I am hunting for the golden stag.
#include <cstdio>
#define int long long
#define X(i) (pre[i]+i)
#define Y(i) (f[i]+(pre[i]+i+l+1)*(pre[i]+i+l+1))
const int maxn = 7e4 + 10;
int n,l,h,t,c[maxn],f[maxn],q[maxn],pre[maxn];
inline long double slope(int i,int j) { return (long double)1*(Y(i)-Y(j))/(X(i)-X(j)); }
signed main() {
	freopen("luogu3195.in","r",stdin);
	freopen("luogu3195.out","w",stdout);
	scanf("%lld%lld",&n,&l);
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&c[i]);
		pre[i] = pre[i-1]+c[i];
	}
	for (int i = 1;i <= n;i++) {
		for (;h < t && slope(q[h],q[h+1]) <= (pre[i]+i)*2;h++);
		f[i] = f[q[h]]+(i-q[h]-1-l+pre[i]-pre[q[h]])*(i-q[h]-1-l+pre[i]-pre[q[h]]);
		for (;h < t && slope(q[t],q[t-1]) >= slope(i,q[t-1]);t--);
		q[++t] = i;
	}
	printf("%lld",f[n]);
	return 0;
}
