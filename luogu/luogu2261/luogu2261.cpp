/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.24.17:36
*Mail          :  1584634848@qq.com
*Problem       :  luogu2261
************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1<<62;
ll n,k,ans;
int main() {
	freopen("luogu2261.in","r",stdin);
	freopen("luogu2261.out","w",stdout);
	scanf("%lld%lld",&n,&k); ans = n*k;
	for (ll l = 1,r;l <= n;l = r+1) {
		if (k/l) r = min(k/(k/l),n);
		else r = n;
		ans -= (k/l)*(r-l+1)*(l+r)>>1;
	}
	printf("%lld",ans);
	return 0;
}
