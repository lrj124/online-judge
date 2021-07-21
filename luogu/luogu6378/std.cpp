//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#define ref(x) (x+n)
using namespace std;
const int maxn = 4e6 + 10;
int n,m,k,nod,tot,cnt,low[maxn],dfn[maxn],scc[maxn],tmp[maxn];
stack<int> s; bool vis[maxn];
vector<int> edge[maxn];
inline void tarjan(int now,int las) {
	s.push(now); vis[now] = true;
	dfn[now] = low[now] = ++cnt;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (now > n+n && to == ref(las)) continue;
		if (!dfn[to]) {
			tarjan(to,now);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (low[now] == dfn[now]) {
		for (tot++;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = tot;
		scc[s.top()] = tot;
		vis[s.top()] = false,s.pop();
	}
}
int main() {
	freopen("luogu6378.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[ref(u)].push_back(v);
		edge[ref(v)].push_back(u);
	}
	nod = n+n;
	for (int i = 1,w;i <= k;i++) {
		scanf("%d",&w);
		for (int j = 1;j <= w;j++) scanf("%d",&tmp[j]);
		for (int j = 1;j <= w;j++)
			for (int k = 1;k <= w;k++)
				if (j ^ k) {
					edge[tmp[j]].push_back(ref(tmp[k]));
				}
	}
	for (int i = 1;i <= n+n;i++) if (!dfn[i]) tarjan(i,0);
	for (int i = 1;i <= n;i++) if (scc[i] == scc[ref(i)]) return printf("NIE")*0;
	printf("TAK");
	return 0;
}
