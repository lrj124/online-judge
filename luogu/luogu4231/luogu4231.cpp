/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.26.16:09
*Mail          :  1584634848@qq.com
*Problem       :  luogu4231
************************************************/
#include <algorithm>
#include <cstdio>
const int maxn = 10000000 + 10;
using ll = long long;
ll pre[maxn],ans,Max;
int n,m;
int main() {
	//freopen("luogu4231.in","r",stdin);
	//freopen("luogu4231.out","w",stdout);
	for (scanf("%d%d",&n,&m);m--;) {
		int l,r; ll s,e,d;
		scanf("%d%d%lld%lld",&l,&r,&s,&e);
		d = (e-s)/(r-l);
		pre[l] += s;
		pre[l+1] += d-s;
		pre[r+1] -= e+d;
		pre[r+2] += e;
	}
	for (int i = 1;i <= n;i++) pre[i] += pre[i-1];
	for (int i = 1;i <= n;i++) {
		pre[i] += pre[i-1];
		ans ^= pre[i];
		Max = std::max(Max,pre[i]);
	}
	printf("%lld %lld",ans,Max);
	return 0;
}
