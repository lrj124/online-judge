/************************************************
*author        :  lrj124
*created time  :  2019.08.30.08:34
*mail          :  1584634848@qq.com
*problem       :  luogu2424
************************************************/
#include <algorithm>
#include <cstdio>
using ll = long long;
inline ll calc(int k) {
	ll ans = k*k;
	for (ll l = 1,r;l <= k;l = r+1) {
		if (k/l) r = std :: min(k/(k/l),1ll*k);
		else r = k;
		ans -= (k/l)*(r-l+1)*(l+r)>>1;
	}
	return k*k-ans;
}
int main() {
	freopen("luogu2424.in","r",stdin);
	freopen("luogu2424.out","w",stdout);
	int l,r;
	scanf("%d%d",&l,&r);
	printf("%lld",calc(r)-calc(l-1));
	return 0;
}
