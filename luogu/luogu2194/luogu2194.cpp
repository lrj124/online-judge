/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.02.20:24
*Mail          :  1584634848@qq.com
*Problem       :  luogu2194
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 100000 + 10;
const int mod = 1e9 + 7;
int n,m,a[maxn],val[maxn],scc[maxn],num[maxn],dfn[maxn],low[maxn],ind,scccnt;
vector<int> edge[maxn];
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
		num[scccnt] = 1;
		for (;s.top() ^ now;vis[s.top()] = false,s.pop()) {
			scc[s.top()] = scccnt;
			if (val[scccnt] > a[s.top()]) {
				val[scccnt] = a[s.top()];
				num[scccnt] = 1;
			} else if (val[scccnt] == a[s.top()]) num[scccnt]++;
		}
		vis[now] = false; s.pop();
	}
}
int main() {
	freopen("luogu2194.in","r",stdin);
	freopen("luogu2194.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) tarjan(i);
	long long ans = 0,ans2 = 1;
	for (int i = 1;i <= scccnt;i++) {
		ans += val[i];
		ans2 = (ans2*num[i])%mod;
	}
	printf("%lld %lld",ans,ans2);
	return 0;
}
