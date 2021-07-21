/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.14.11:13
*Mail          :  1584634848@qq.com
*Problem       :  luogu3243
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int,int>;
const int maxn = 100000 + 10;
int d,n,m,ans[maxn],deg[maxn];
vector<int> edge[maxn];
inline void toposort() {
	priority_queue<int> q;
	for (int i = 1;i <= n;i++) if (!deg[i]) q.push(i);
	for (int now;q.size();) {
		now = q.top(); q.pop();
		ans[++ans[0]] = now;
		for (size_t i = 0;i < edge[now].size();i++) {
			int to = edge[now][i];
			if (!--deg[to]) q.push(to);
		}
	}
}
int main() {
	freopen("luogu3243.in","r",stdin);
	freopen("luogu3243.out","w",stdout);
	for (scanf("%d",&d);d--;ans[0] = 0) {
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++) { deg[i] = 0; edge[i].clear(); }
		for (int i = 1,u,v;i <= m;i++) {
			scanf("%d%d",&u,&v); deg[u]++;
			edge[v].push_back(u);
		}
		toposort();
		if (ans[0] ^ n) puts("Impossible!");
		else for (int i = ans[0];i;i--) printf("%d%c",ans[i],i ^ 1 ? ' ' : '\n');
	}
	return 0;
}
