/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.15.19:59
*Mail          :  1584634848@qq.com
*Problem       :  luogu3868
************************************************/
#include <cstdio>
#define int long long
const int maxn = 10 + 10;
int n,ans,mul(1),a[maxn],b[maxn];
inline void exgcd(int a,int b,int &x,int &y) {
	if (!b) { x = 1,y = 0; return; }
	exgcd(b,a%b,x,y);
	int tmp = x; x = y; y = tmp-a/b*y;
}
inline int mull(int x,int y,int mod) {
	int p = 1,ans = 0;
	if (y < 0) y *= -1,p = -1;
	for (;y;y >>= 1,x = (x+x)%mod) if (y&1) ans = (ans+x)%mod;
	return ans*p;
}
signed main() {
	freopen("luogu3868.in","r",stdin);
	freopen("luogu3868.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for (int i = 1;i <= n;i++) scanf("%lld",&b[i]),mul *= b[i];
	for (int i = 1;i <= n;i++) {
		int m = mul/b[i],t,_;
		exgcd(m,b[i],t,_);
		t = (t+mul)%mul;
		ans = (ans+mull(mull(m,t,mul),a[i],mul))%mul;
	}
	printf("%lld",ans%mul);
	return 0;
}
