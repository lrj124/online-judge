/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.13.16:09
*Mail          :  1584634848@qq.com
*Problem       :  luogu1495
************************************************/
#include <cstdio>
#define int ll
using ll = long long;
const int maxn = 10 + 10;
int n,tmp,ans,mul(1),M[maxn],a[maxn],m[maxn],t[maxn];
inline void exgcd(int a,int b,int &x,int &y) {
	if (b == 0) { x = 1,y = 0; return; }
	exgcd(b,a%b,x,y);
	int tmp = x; x = y; y = tmp-a/b*y;
}
signed main() {
	freopen("luogu1495.in","r",stdin);
	freopen("luogu1495.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1;i <= n;i++) { scanf("%lld%lld",&m[i],&a[i]); mul *= m[i]; }
	for (int i = 1;i <= n;i++) {
		M[i] = mul/m[i];
		exgcd(M[i],m[i],t[i],tmp);
		t[i] = (t[i]+m[i])%m[i];
		ans += a[i]*M[i]*t[i];
	}
	printf("%lld",ans%mul);
	return 0;
}
