//I am hunting for the golden stag.
#include <functional>
#include <algorithm>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9;
int n,m,q,u,v,t,del,a[maxn];
queue<int> cut[3];
double p;
signed main() {
	freopen("luogu2827.in","r",stdin);
	freopen("luogu2827.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t); p = 1.*u/v;
	for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for (int i = 1;i <= n;i++) cut[0].push(a[i]);
	for (int i = 1,num;i <= m;i++) {
		for (int j = 0,len = -inf;j < 3;j++) if (cut[j].size() && cut[j].front() > len) { len = cut[j].front(); num = j; }
		int c = cut[num].front()+(i-1)*q; cut[num].pop();
		if (!(i%t)) printf("%lld ",c);
		cut[1].push(c*u/v-q*(i-1)-q);
		cut[2].push(c-c*u/v-q*(i-1)-q);
	}
	puts("");
	for (int i = 1,num;i <= n+m;i++) {
		for (int j = 0,len = -inf;j < 3;j++) if (cut[j].size() && cut[j].front() > len) { len = cut[j].front(); num = j; }
		if (!(i%t)) printf("%lld ",cut[num].front()+m*q);
		cut[num].pop();
	}
	return 0;
}
