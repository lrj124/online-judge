//2021.07.15 08:57 by lrj124.
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n,k,f[maxn][21],val[maxn];
vector<int> edge[maxn];
inline void init(int now,int fa) {
	for (int i = 0;i <= k;i++) f[now][i] = val[now];
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa) {
			init(to,now);
			for (int j = 1;j <= k;j++) f[now][j] += f[to][j-1];
		}
	}
}
inline void dfs(int now,int fa) {
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa) {
			for (int j = k;j >= 1;j--) f[to][j] += f[now][j-1]-(j >= 2 ? f[to][j-2] : 0);
			dfs(to,now);
		}
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1;i <= n;i++) scanf("%d",&val[i]);
	init(1,0);
	dfs(1,0);
	for (int i = 1;i <= n;i++) printf("%d\n",f[i][k]);
	return 0;
}
