/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.09.15:53
*Mail          :  1584634848@qq.com
*Problem       :  luogu4782
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 2e6 + 10;
int n,m,low[maxn],dfn[maxn],scc[maxn],scccnt,ind;
vector<int> edge[maxn];
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	low[now] = dfn[now] = ++ind;
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
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = scccnt;
		vis[now] = false,s.pop();
	}
}
int main() {
    freopen("luogu4782.in","r",stdin);
    freopen("luogu4782.out","w",stdout);
    scanf("%d%d",&n,&m);
	for (int i = 1,a,va,b,vb;i <= m;i++) {
		scanf("%d%d%d%d",&a,&va,&b,&vb);
		edge[a+n*va].push_back(b+n*(vb^1));
		edge[b+n*vb].push_back(a+n*(va^1));
	}
	for (int i = 1;i <= n*2;i++) if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= n;i++) if (scc[i] == scc[i+n]) return puts("IMPOSSIBLE")*0;
	puts("POSSIBLE");
	for (int i = 1;i <= n;i++) printf("%d ",scc[i] < scc[i+n]);
    return 0;
}
