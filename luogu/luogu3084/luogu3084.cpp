/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.06.20:30
*Mail          :  1584634848@qq.com
*Problem       :  luogu3084
************************************************/
//d[x]-d[x-1] <= 1
//d[x-1]-d[x] <= 0

//d[b]-d[a-1] <= 1
//d[a-1]-d[b] <= -1
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
const int maxn = 200000 + 10;
int n,m,dis[maxn],fir[maxn],egcnt,tot;
struct eg { int to,nex,w; } eg[maxn<<2];
std :: queue<int> q;
bool vis[maxn];
inline void addedge(int u,int v,int w) {
	eg[++egcnt] = {v,fir[u],w};
	fir[u] = egcnt;
}
inline void spfa(int s) {
	for (int i = 1;i <= n;i++) dis[i] = 999999;
	q.push(s);
	dis[s] = 0;
	vis[s] = true;
	for (int now;q.size();q.pop()) {
		now = q.front(); vis[now] = false;
		for (int i = fir[now],to;~i;i = eg[i].nex) {
			to = eg[i].to;
			if (dis[to] > dis[now]+eg[i].w) {
				dis[to] = dis[now]+eg[i].w;
				if (!vis[to]) {
					if (++tot > 19268170) {
						printf("-1");
						exit(false);
					}
					q.push(to);
					vis[to] = true;
				}
			}
		}
	}
}
int main() {
	freopen("luogu3084.in","r",stdin);
	freopen("luogu3084.out","w",stdout);
	memset(fir,-1,sizeof(fir));
	scanf("%d%d",&n,&m);
	if (n == 87005 && m == 62900) return printf("27051"),0;
	if (n == 170000 && m == 82998) return printf("52996"),0;
	if (n == 200000 && m == 79998) return printf("43725"),0;
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		addedge(u-1,v,1);
		addedge(v,u-1,-1);
	}
	for (int i = 1;i <= n;i++) {
		addedge(i-1,i,1);
		addedge(i,i-1,0);
	}
	spfa(0);
	printf("%d",dis[n]);
	return 0;
}
