/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.23.17:42
*Mail          :  1584634848@qq.com
*Problem       :  luogu2022
************************************************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll k,m,base = 1;
inline ll calc(ll x) {
	ll ans = 0;
	for (ll tmp = x;tmp;tmp /= 10,base *= 10);
	base /= 10; for (ll tmp = base;x;x /= 10,tmp /= 10) ans += x-tmp+1;
	return ans;
}
int main() {
	freopen("luogu2022.in","r",stdin);
	freopen("luogu2022.out","w",stdout);
	scanf("%lld%lld",&k,&m); m -= calc(k);
	if (!m) printf("%lld",k);
	else if (m < 0 || base == k) printf("0");
	else {
		base *= 10;
		for (ll tmp = (k-base/10)*10;m > tmp;m -= tmp,base *= 10,tmp *= 10);
		printf("%lld",base+m-1);
	}
	return 0;
}
