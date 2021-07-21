/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.30.19:45
*Mail          :  1584634848@qq.com
*Problem       :  luogu2015
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100 + 10;
int n,q,f[maxn][maxn],fir[maxn],egcnt;
struct Edge { int to,nex,w; } eg[maxn];
inline void addedge(int u,int v,int w) {
	eg[++egcnt] = { v,fir[u],w }; fir[u] = egcnt;
	eg[++egcnt] = { u,fir[v],w }; fir[v] = egcnt;
}
inline int dfs(int now,int fa) {
	int siz = 1;
	for (int i = fir[now];i;i = eg[i].nex) {
		int to = eg[i].to,w = eg[i].w;
		if (to ^ fa) {
			int son = dfs(to,now);
			siz += son;
			for (int j = min(q,siz);j;j--)
				for (int k = min(j-1,siz);~k;k--)
					f[now][j] = max(f[now][j],f[now][j-k-1]+f[to][k]+w);
		}
	}
	return siz;
}
int main() {
	freopen("luogu2015.in","r",stdin);
	freopen("luogu2015.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1,u,v,w;i < n;i++) {
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	dfs(1,0);
	printf("%d",f[1][q]);
	return 0;
}
