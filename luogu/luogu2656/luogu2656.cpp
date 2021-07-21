/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.20.10:25
*Mail          :  1584634848@qq.com
*Problem       :  luogu2656
************************************************/
#include <algorithm>
#include <utility>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 8e4 + 10;
int n,m,st,ans,cnt,tot,low[maxn],dfn[maxn],dis[maxn],scc[maxn],val[maxn];
vector<pair<int,pair<int,int> > > edge[maxn];
vector<pii> e[maxn];
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	dfn[now] = low[now] = ++cnt;
	s.push(now); vis[now] = true;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i].first;
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (low[now] == dfn[now]) {
		for (tot++;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = tot;
		scc[s.top()] = tot;
		vis[s.top()] = false,s.pop();
	}
}
inline void spfa() {
	fill(vis+1,vis+n+1,false);
	dis[scc[st]] = val[scc[st]];
	queue<int> q;
	for (q.push(scc[st]),vis[scc[st]] = true;q.size();) {
		int now = q.front(); q.pop();
		vis[now] = false;
		for (size_t i = 0;i < e[now].size();i++) {
			int to = e[now][i].first,w = e[now][i].second;
			if (dis[to] < dis[now]+w+val[to]) {
				dis[to] = dis[now]+w+val[to];
				if (!vis[to]) {
					q.push(to);
					vis[to] = true;
				}
			}
		}
	}
}
signed main() {
	freopen("luogu2656.in","r",stdin);
	freopen("luogu2656.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1,tmp,u,v,w,sum;i <= m;i++) {
		double k; scanf("%lld%lld%lld%lf",&u,&v,&w,&k);
		for (tmp = w,sum = 0;w;w = 1.*w*k) sum += w;
		edge[u].push_back(make_pair(v,make_pair(tmp,sum)));
	}
	scanf("%lld",&st);
	for (int i = 1;i <= n;i++) if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (size_t j = 0;j < edge[i].size();j++) {
			int to = edge[i][j].first,w = edge[i][j].second.first;
			if (scc[i] ^ scc[to]) e[scc[i]].push_back(make_pair(scc[to],w));
			else val[scc[i]] += edge[i][j].second.second;
		}
	spfa();
	for (int i = 1;i <= tot;i++) ans = max(ans,dis[i]);
	printf("%lld",ans);
	return 0;
}
