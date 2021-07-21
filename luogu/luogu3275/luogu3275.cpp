/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.11.19:14
*Mail          :  1584634848@qq.com
*Problem       :  luogu3275
************************************************/
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100000 + 10;
const int inf = 1e8;
int n,k,dis[maxn],fir[maxn],cnt[maxn],egcnt;
struct edge { int to,nex,w; } eg[maxn<<2];
bool vis[maxn],fuck;
inline void addedge(int u,int v,int w) { eg[++egcnt] = { v,fir[u],w }; fir[u] = egcnt; }
inline void spfa(int s) {
	queue<int> q;
	dis[s] = 0;
	cnt[s] = 1;
	q.push(s);
	vis[s] = true;
	for (int now;q.size();) {
		now = q.front(); q.pop();
		vis[now] = false;
		for (size_t i = fir[now];i;i = eg[i].nex) {
			int to = eg[i].to,w = eg[i].w;
			if (dis[to] < dis[now]+w) {
				dis[to] = dis[now]+w;
				cnt[to] = cnt[now]+1;
				if (cnt[to] > n+1) {
					printf("-1");
					fuck = true;
					return;
				}
				if (!vis[to]) {
					q.push(to);
					vis[to] = true;
				}
			}
		}
	}
}
int main() {
 	freopen("luogu3275.in","r",stdin);
 	freopen("luogu3275.out","w",stdout);
	for (scanf("%d%d",&n,&k);k--;) {
		int x,a,b;
		scanf("%d%d%d",&x,&a,&b);
		if (x == 1) addedge(a,b,0),addedge(b,a,0);
		else if (x == 2) addedge(a,b,1);
		else if (x == 3) addedge(b,a,0);
		else if (x == 4) addedge(b,a,1);
		else if (x == 5) addedge(a,b,0);
		if (!(x&1) && a == b) return printf("-1")*0;
	}
	for (int i = n;i >= 1;i--) addedge(0,i,1);
	spfa(0);
	if (fuck) return 0;
	long long ans = 0;
	for (int i = 1;i <= n;i++) ans += dis[i];
	printf("%lld",ans);
    return 0;
}
