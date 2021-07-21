/************************************************
*Author        :  lrj124
*Created Time  :  2020.08.16.15:07
*Mail          :  1584634848@qq.com
*Problem       :  cf1238f
************************************************/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 3e5 + 10;
int T,n,ans,f[maxn],deg[maxn];
vector<int> edge[maxn];
inline void dfs(int now,int fa) {
	int Max = 0,seMax = 0;
	f[now] = 1;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa) {
			dfs(to,now);
			if (f[to] > Max) { seMax = Max; Max = f[to]; }
			else seMax = max(seMax,f[to]);
			f[now] = max(f[now],f[to]+deg[now]-1);
		}
	}
	ans = max(ans,Max+seMax+deg[now]-(seMax != 0)-(Max != 0)+1);
}
int main() {
	freopen("cf1238f.in","r",stdin);
	freopen("cf1238f.out","w",stdout);
	for (scanf("%d",&T);T--;ans = 0) {
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) {
			edge[i].clear();
			f[i] = deg[i] = 0;
		}
		for (int i = 1,u,v;i < n;i++) {
			scanf("%d%d",&u,&v);
			deg[u]++,deg[v]++;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
