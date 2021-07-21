/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.20.21:50
*Mail          :  1584634848@qq.com
*Problem       :  cf1042d
************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
const int maxn = 200000 + 10;
ll pre[maxn],n,t,ans;
inline void cdq(ll l,ll r) {
	if (l == r) return;
	ll mid = l+r>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	for (int a = l,b = mid+1;a <= mid && b <= r;)
		if (pre[a]+t <= pre[b]) a++;
		else ans += mid-a+1,b++;
	sort(pre+l,pre+r+1);
}
int main() {
	freopen("cf1042d.in","r",stdin);
	freopen("cf1042d.out","w",stdout);
	cin >> n >> t;
	for (ll i = 1,x;i <= n;i++) {
		cin >> x;
		pre[i] = pre[i-1]+x;
	}
	cdq(0,n);
	cout << ans;
	return 0;
}
