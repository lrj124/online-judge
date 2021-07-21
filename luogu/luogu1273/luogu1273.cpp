/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.27.10:02
*Mail          :  1584634848@qq.com
*Problem       :  luogu1273
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using std :: max;
const int maxn = 3000 + 10;
int n,m,first[maxn],f[maxn][maxn],val[maxn],cnt,size[maxn];
struct eg { int to,nex,w; } eg[maxn];
inline void addedge(int u,int v,int w) {
	eg[++cnt] = {v,first[u],w}; first[u] = cnt;
	eg[++cnt] = {u,first[v],w}; first[v] = cnt;
}
inline void dfs(int now,int fa) {
	size[now] = 1;
	if (now > n-m) {
		f[now][1] = val[now];
		return;
	}
	for (int i = first[now],to;~i;i = eg[i].nex) {
		to = eg[i].to;
		if (to ^ fa) {
			dfs(to,now);
			size[now] += size[to];
			for (int k = size[now];k;k--)
				for (int t = 1;t <= k && t <= size[to];t++)
					f[now][k] = max(f[now][k],f[now][k-t]+f[to][t]-eg[i].w);
		}
	}
}
int main() {
	freopen("luogu1273.in","r",stdin);
	freopen("luogu1273.out","w",stdout);
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	for (int i = 1,k,to,w;i <= n-m;i++)
		for (scanf("%d",&k);k--;scanf("%d%d",&to,&w),addedge(i,to,w));
	for (int i = n-m+1;i <= n;i++) scanf("%d",&val[i]);
	memset(f,-10,sizeof(f));
	for (int i = 0;i <= n;i++) f[i][0] = 0;
	dfs(1,0);
	for (int i = m;i;i--)
		if (f[1][i] >= 0) return printf("%d",i),0;
	return 0;
}
