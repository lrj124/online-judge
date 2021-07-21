#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const double eps = 1e-8;
const int maxn = 1000 + 10;
typedef long long ll;
struct flags { ll o,a,b,k; } q[maxn<<1];
vector<pair<int,double> > edge[maxn];
ll n,s,t,cnt[maxn];
double dis[maxn];
bool vis[maxn];
inline bool check(double mid) {
	for (ll i = 0;i <= n;i++) {
		edge[i].clear();
		vis[i] = cnt[i] = dis[i] = 0;
	}
	for (ll i = 1;i <= s+t;i++) {
		if (q[i].o == 1) edge[q[i].b].push_back(make_pair(q[i].a,1.*q[i].k-mid));
		if (q[i].o == 2) edge[q[i].b].push_back(make_pair(q[i].a,1./(1.*q[i].k+mid)));
		if (q[i].o == 3) {
			edge[q[i].a].push_back(make_pair(0,1./q[i].k));
			edge[0].push_back(make_pair(q[i].a,1.*q[i].k));
		}
	}
	queue<ll> q;
	for (;q.size();q.pop());
	for (q.push(0),dis[0] = 1,vis[0] = true;q.size();) {
		ll now = q.front(); q.pop();
		vis[now] = false;
		for (size_t i = 0;i < edge[now].size();i++) {
			double w = edge[now][i].second;
			ll to = edge[now][i].first;
			if (dis[to] < dis[now]*w) {
				dis[to] = dis[now]*w;
				if ((cnt[to] = cnt[now]+1) >= n) return true;
				if (!vis[to]) { q.push(to); vis[to] = true; }
			}
		}
	}
	return false;
}
signed main() {
	freopen("luogu4926.in","r",stdin);
	freopen("luogu4926.out","w",stdout);
	scanf("%lld%lld%lld",&n,&s,&t);
	double l = 0,r = 1e10,mid,ans = -124;
	for (ll i = 1;i <= s;i++) scanf("%lld%lld%lld%lld",&q[i].o,&q[i].a,&q[i].b,&q[i].k);
	for (ll i = 1;i <= t;i++) scanf("%lld%lld",&q[s+i].a,&q[s+i].k),q[s+i].o = 3;
	for (;r-l >= eps;check(mid = (l+r)/2.) ? ans = mid,l = mid+eps : r = mid-eps);
	if (ans < 0) printf("-1");
	else printf("%.9lf",ans);
	return 0;
}
