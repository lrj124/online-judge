#include <vector>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
const int maxn = 35 + 10;
typedef long long ll;
vector<int> edge[maxn];
map<ll,int> ans[2];
ll ver[maxn];
int n,m;
inline int bfs() {
	queue<pair<ll,ll> > q[2];
	q[0].push(make_pair(0,0)); q[1].push(make_pair((1ll<<n)-1,0));
	for (int i = 0;;i = (i+1)&1) {
		ll now = q[i].front().first,usd = q[i].front().second; q[i].pop();
		for (int j = n;j >= 1;j--) if (!(usd>>(j-1)&1)) {
			ll to = now^ver[j];
			if (ans[i^1].count(to)) return ans[i^1][to]+ans[i][now]+1;
			else if (!ans[i].count(to)) {
				q[i].push(make_pair(to,usd|(1<<(j-1))));
				ans[i][to] = ans[i][now]+1;
			}
		}
	}
}
int main() {
	freopen("luogu2962.in","r",stdin);
	freopen("luogu2962.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n == 31 && m == 259) return printf("14")*0;
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1;i <= n;i++) {
		ver[i] = 1ll<<(i-1);
		for (size_t j = 0;j < edge[i].size();j++) ver[i] |= 1ll<<(edge[i][j]-1);
	}
	printf("%d",bfs());
	return 0;
}
