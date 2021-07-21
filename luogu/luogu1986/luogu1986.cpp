/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.30.21:57
*Mail          :  1584634848@qq.com
*Problem       :  luogu1986
************************************************/
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100000 + 10;
int n,m,dis[maxn],fir[maxn],egcnt;
bool vis[maxn];
queue<int> q;
struct edge { int to,nex,w; } eg[maxn];
inline void addedge(int u,int v,int w) { eg[++egcnt] = { v,fir[u],w }; fir[u] = egcnt; }
inline void spfa() {
	for (int i = 0;i <= n;i++) {
		q.push(i);
		vis[i] = true;
	}
	for (int now;q.size();) {
		now = q.front(); q.pop();
		vis[now] = false;
		for (int i = fir[now];i;i = eg[i].nex)
			if (dis[eg[i].to] < dis[now]+eg[i].w) {
				dis[eg[i].to] = dis[now]+eg[i].w;
				if (!vis[eg[i].to]) {
					vis[eg[i].to] = true;
					q.push(eg[i].to);
				}
			}
	}
}
int main() {
	freopen("luogu1986.in","r",stdin);
	freopen("luogu1986.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) {
		addedge(i,i-1,-1);
		addedge(i-1,i,0);
	}
	for (int a,b,c;m--;) {
		scanf("%d%d%d",&a,&b,&c);
		addedge(a-1,b,c);
	}
	spfa();
	printf("%d",dis[n]);
	return 0;
}
