#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
ll ans,n,k,l,r,a[100001];
int main(){
	cin >> n >> k;
	for (ll i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1); ans = a[n]-a[1];
	for (ll l = 1,r = n,x;l < r && k;ans -= x) k -= l < n-r+1 ? (x = min(a[l+1]-a[l],k/l))*l++ : (x = min(a[r]-a[r-1],k/(n-r+1)))*(n-r--)+x;
	cout << ans;
	return 0;
}
