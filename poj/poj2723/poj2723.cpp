/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.10.20:21
*Mail          :  1584634848@qq.com
*Problem       :  poj2723
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 10000 + 10;
int n,m,low[maxn],dfn[maxn],scc[maxn],scccnt,ind;
pair<int,int> key[maxn],door[maxn];
vector<int> edge[maxn];
bool vis[maxn];
stack<int> s;
inline void tarjan(int now) {
	dfn[now] = low[now] = ++ind;
	vis[now] = true,s.push(now);
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
inline bool check(int mid) {
	ind = scccnt = 0;
	for (int i = 1;i <= 4*n;i++) edge[i].clear(),low[i] = dfn[i] = 0;
	for (int i = 1;i <= n;i++) {
		edge[key[i].first].push_back(key[i].second+2*n);
		edge[key[i].second].push_back(key[i].first+2*n);
	}
	for (int i = 1;i <= mid;i++) {
		edge[door[i].first+2*n].push_back(door[i].second);
		edge[door[i].second+2*n].push_back(door[i].first);
	}
	for (int i = 1;i <= 4*n;i++) if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= 2*n;i++) if (scc[i] == scc[i+2*n]) return false;
	return true;
}
int main() {
	freopen("poj2723.in","r",stdin);
	freopen("poj2723.out","w",stdout);
	for (;scanf("%d%d",&n,&m),n && m;) {
		for (int i = 1,x,y;i <= n;i++) {
			scanf("%d%d",&x,&y); x++,y++;
			key[i] = make_pair(x,y);
		}
		for (int i = 1,x,y;i <= m;i++) {
			scanf("%d%d",&x,&y); x++,y++;
			door[i] = make_pair(x,y);
		}
		int l = 0,r = m,ans;
		for (int mid;l <= r;check(mid = l+r>>1) ? l = mid+1,ans = mid : r = mid-1);
		printf("%d\n",ans);
	}
    return 0;
}
