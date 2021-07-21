/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.03.16:30
*Mail          :  1584634848@qq.com
*Problem       :  luogu3119
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1000000 + 10;
int n,m,dfn[maxn],low[maxn],scc[maxn],scccnt,ind,siz[maxn];
vector<int> edge[maxn];
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	dfn[now] = low[now] = ++ind;
	vis[now] = true; s.push(now);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (dfn[now] == low[now]) {
		scc[now] = ++scccnt;
		siz[scccnt] = 1;
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) {
			scc[s.top()] = scccnt;
			siz[scccnt]++;
		}
		vis[now] = false; s.pop();
	}
}
struct { int to,nex; } eg[maxn<<4];
int fir[maxn],egcnt,dis[maxn];
inline void addedge(int u,int v) { eg[++egcnt] = { v,fir[u] }; fir[u] = egcnt; }
inline void spfa(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
	for (int now;q.size();) {
		now = q.front(); q.pop();
		vis[now] = false;
		for (int i = fir[now];i;i = eg[i].nex) {
			int to = eg[i].to;
			if (dis[to] < dis[now]+siz[now]) {
				dis[to] = dis[now]+siz[now];
				if (!vis[to]) {
					q.push(to);
					vis[to] = true;
				}
			}
		}
	}
}
int main() {
 	freopen("luogu3119.in","r",stdin);
 	freopen("luogu3119.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= scccnt;i++) siz[i+scccnt] = siz[i];
	for (int i = 1;i <= n;i++)
		for (size_t j = 0;j < edge[i].size();j++)
			if (scc[i] ^ scc[edge[i][j]]) {
				addedge(scc[i],scc[edge[i][j]]);
				addedge(scc[i]+scccnt,scc[edge[i][j]]+scccnt);
				addedge(scc[edge[i][j]],scc[i]+scccnt);
			}
	spfa(scc[1]);
	printf("%d",dis[scc[1]+scccnt]);
	return 0;
}
