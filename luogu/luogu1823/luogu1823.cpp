/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.14.10:30
*Mail          :  1584634848@qq.com
*Problem       :  luogu1823
************************************************/
#include <cstdio>
#include <stack>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int maxn = 500000 + 10;
stack<pii> s;
ll n,ans;
int main() {
	freopen("luogu1823.in","r",stdin);
	freopen("luogu1823.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1,x;i <= n;i++) {
		scanf("%d",&x);
		int cnt = 1;
		for (;s.size() && s.top().first <= x;s.pop()) {
			ans += s.top().second;
			if (s.top().first == x) cnt += s.top().second;
		}
		if (s.size()) ans++;
		s.push(make_pair(x,cnt));
	}
	printf("%lld",ans);
	return 0;
}
