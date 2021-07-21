/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.27.14:21
*Mail          :  1584634848@qq.com
*Problem       :  2b
************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
ll n,a[300001];
double ans;
int main() {
	//freopen("2b.in","r",stdin);
	//freopen("2b.out","w",stdout);
	scanf("%lld",&n);
	for (ll i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<ll>());
	for (ll i = 1;i <= n;i++) {
		a[i] += a[i-1];
		ans = max(ans,1.*a[i]*a[i]/i);
	}
	printf("%lf",ans);
	return 0;
}
