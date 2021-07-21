/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.04.20:07
*Mail          :  1584634848@qq.com
*Problem       :  luogu3957
************************************************/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using ll = long long;
using namespace std;
const int maxn = 500000 + 10;
ll n,d,k,x[maxn],s[maxn],f[maxn],head,tail;
struct que { ll val,num; } q[maxn];
inline bool check(ll g) {
	head = 1; tail = 0;
	ll r(0);
	memset(q,0,sizeof(q));
	memset(f,0x7f,sizeof(f));
	f[0] = 0;
	for (ll i = 0;i <= n;i++) {
		for (;x[r]+max(1ll,d-g) <= x[i]/* && x[r]+d+g >= x[i]*/;r++) {
			for (;head <= tail && q[tail].val <= f[r];tail--);
			q[++tail] = { f[r],x[r] };
		}
		for (;head <= tail && q[head].num+d+g < x[i];head++);
		if (head <= tail) f[i] = q[head].val+s[i];
		if (f[i] >= k) return true;
	}
	return false;
}
int main() {
	freopen("luogu3957.in","r",stdin);
	freopen("luogu3957.out","w",stdout);
	scanf("%lld%lld%lld",&n,&d,&k);
	x[0] = s[0] = 0;
	for (ll i = 1;i <= n;i++) scanf("%lld%lld",&x[i],&s[i]);
	ll l = 0,r = 1e12;
	for (ll mid;l < r;mid = l+r>>1,check(mid) ? r = mid : l = mid+1);
	printf("%lld",l == 1e12 ? -1 : l);
	return 0;
}
