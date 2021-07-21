//2021.07.13 08:31 by lrj124.
#include <cstdarg>
#include <cstring>
#include <cstdio>
typedef long long ll;
ll mod,a,c,x0,n,g;
inline ll mul(ll x,ll y) {
	ll ans = 0;
	for (;y;x = (x+x)%mod,y >>= 1) if (y & 1) ans = (ans+x)%mod;
	return ans;
}
struct matrix {
	ll a[3][3];
	int n,m;
	inline void clear() { memset(a,0,sizeof a); }
	inline void set(int k,int l,...) {
		va_list args;
		va_start(args,k*l);
		n = k; m = l;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++) a[i][j] = va_arg(args,ll);
		va_end(args);
	}
	inline matrix operator * (matrix x) const {
		matrix ans;
		ans.clear();
		ans.n = n; ans.m = x.m;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= x.m;j++)
				for (int k = 1;k <= m;k++) (ans.a[i][j] += mul(a[i][k],x.a[k][j])) %= mod;
		return ans;
	}
} base,arr;
inline matrix power(matrix x,ll y) {
	matrix ans; ans.set(2,2,1,0,0,1);
	for (;y;x = x*x,y >>= 1) if (y & 1) ans = ans*x;
	return ans;
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&mod,&a,&c,&x0,&n,&g);
	base.set(2,2,a,1,0,1);
	arr.set(2,1,x0,c);
	printf("%lld\n",(power(base,n)*arr).a[1][1]%g);
	return 0;
}
