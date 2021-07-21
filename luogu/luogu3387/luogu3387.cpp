/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.21:31
*Mail          :  1584634848@qq.com
*Problem       :  luogu3387
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e4 + 10;
int n,m,a[maxn],val[maxn],scc[maxn],dfn[maxn],low[maxn],ind,scccnt,f[maxn],ans;
vector<int> edge[maxn],edge2[maxn];
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	vis[now] = true; s.push(now);
	dfn[now] = low[now] = ++ind;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (dfn[now] == low[now]) {
		scc[now] = ++scccnt;
		val[scccnt] = a[now];
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) {
			scc[s.top()] = scccnt;
			val[scccnt] += a[s.top()];
		}
		vis[now] = false; s.pop();
	}
}
inline void dp(int now) {
	for (size_t i = 0;i < edge2[now].size();i++) {
		int to = edge2[now][i];
		if (!f[to]) dp(to);
		f[now] = max(f[now],f[to]);
	}
	f[now] += val[now];
}
int main() {
	freopen("luogu3387.in","r",stdin);
	freopen("luogu3387.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (size_t j = 0;j < edge[i].size();j++)
			if (scc[i] ^ scc[edge[i][j]]) edge2[scc[i]].push_back(scc[edge[i][j]]);
	for (int i = 1;i <= scccnt;i++)
		if (!f[i]) dp(i);
	for (int i = 1;i <= scccnt;i++) ans = max(ans,f[i]);
	printf("%d",ans);
	return 0;
}
