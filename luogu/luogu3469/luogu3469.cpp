/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.04.12:20
*Mail          :  1584634848@qq.com
*Problem       :  luogu3469
************************************************/
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 500000 + 10;
int n,m,low[maxn],dfn[maxn],siz[maxn],ind,root;
vector<int> edge[maxn];
bool cut[maxn];
ll ans[maxn];
inline void tarjan(int now) {
	low[now] = dfn[now] = ++ind;
	siz[now] = 1;
	int flag = 0,sum = 0;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			siz[now] += siz[to];
			low[now] = min(low[now],low[to]);
			if (low[to] >= dfn[now]) {
				flag++;
				sum += siz[to];
				ans[now] += 1ll*siz[to]*(n-siz[to]);
				if (flag >= 2 || now ^ root) cut[now] = true;
			}
		} else low[now] = min(low[now],dfn[to]);
	}
	if (cut[now]) ans[now] += n+1ll*(n-sum-1)*(sum+1)-1;
	else ans[now] = 2*(n-1);
}
int main() {
	freopen("luogu3469.in","r",stdin);
	freopen("luogu3469.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i]) { root = i; tarjan(i); }
	for (int i = 1;i <= n;i++) printf("%lld\n",ans[i]);
	return 0;
}
