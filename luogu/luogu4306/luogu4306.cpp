/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.21:50
*Mail          :  1584634848@qq.com
*Problem       :  luogu4306
************************************************/
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 1e4 + 10;
int n,m,a[maxn],siz[maxn],scc[maxn],dfn[maxn],low[maxn],ind,scccnt,deg[maxn],ans;
vector<int> edge[maxn],edge2[maxn];
bitset<maxn> f[maxn];
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
		siz[scccnt] = 1;
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) {
			scc[s.top()] = scccnt;
			siz[scccnt]++;
		}
		vis[now] = false; s.pop();
	}
}
inline void toposort() {
	queue<int> q;
	for (int i = 1;i <= scccnt;i++) {
		f[i][i] = 1;
		if (!deg[i]) q.push(i);
	}
	for (int now;q.size();) {
		now = q.front(); q.pop();
		for (size_t i = 0;i < edge2[now].size();i++) {
			int to = edge2[now][i];
			f[now] |= f[to];
			if (!--deg[to]) q.push(to);
		}
	}
}
int main() {
	freopen("luogu4306.in","r",stdin);
	freopen("luogu4306.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int j = 1,x;j <= n;j++) {
			scanf("%1d",&x);
			if (x) edge[i].push_back(j);
		}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++)
		for (size_t j = 0;j < edge[i].size();j++)
			if (scc[i] ^ scc[edge[i][j]]) {
				edge2[scc[i]].push_back(scc[edge[i][j]]);
				deg[scc[edge[i][j]]]++;
			}
	toposort();
	for (int i = 1;i <= scccnt;i++)
		for (int j = 1;j <= scccnt;j++)
			if (f[i][j]) ans += siz[i]*siz[j];
	printf("%d",ans);
	return 0;
}
