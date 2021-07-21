/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.08.21:01
*Mail          :  1584634848@qq.com
*Problem       :  luogu4171
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 2000 + 10;
int T,n,m,ind,low[maxn],dfn[maxn],scc[maxn],scccnt;
vector<int> edge[maxn];
bool vis[maxn],flag;
stack<int> s;
inline void tarjan(int now) {
	dfn[now] = low[now] = ++ind;
	vis[now] = true; s.push(now);
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],low[to]);
	}
	if (dfn[now] == low[now]) {
		scc[now] = ++scccnt;
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = scccnt;
		vis[s.top()] = false,s.pop();
	}
}
int main() {
	freopen("luogu4171.in","r",stdin);
	freopen("luogu4171.out","w",stdout);
	for (scanf("%d",&T);T--;ind = scccnt = flag = 0) {
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n<<1;i++) edge[i].clear();
		for (int i = 1,u,v,q,p;i <= m;i++) {
			char a[10],b[10];
			scanf("%s%s",a,b);
			q = a[0] == 'm',p = b[0] == 'm';
			u = atoi(a+1),v = atoi(b+1);
			edge[u+q*n].push_back(v+(p^1)*n);
			edge[v+p*n].push_back(u+(q^1)*n);
		}
		memset(vis,false,sizeof(vis));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		for (int i = 1;i <= n<<1;i++) if (!dfn[i]) tarjan(i);
		for (int i = 1;i <= n;i++) if (scc[i] == scc[i+n]) { flag = true; break; }
		puts(flag ? "BAD" : "GOOD");
	}
	return 0;
}
