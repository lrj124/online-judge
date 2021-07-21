/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.10.19:24
*Mail          :  1584634848@qq.com
*Problem       :  luogu2149
************************************************/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
using pii = pair<int,int>;
const int maxn = 1500 + 10;
int n,m,s1,t1,s2,t2,dis_s1[maxn],dis_t1[maxn],dis_s2[maxn],dis_t2[maxn],fir[maxn],egcnt;
struct Edge { int to,nex,w; } eg[maxn<<10];
bool vis[maxn];
inline void addedge(int u,int v,int w) {
	eg[++egcnt] = {v,fir[u],w}; fir[u] = egcnt;
	eg[++egcnt] = {u,fir[v],w}; fir[v] = egcnt;
}
priority_queue<pii,vector<pii>,greater<pii> > q;
inline void dijkstra(int s,int *dis) {
	for (int i = 1;i <= n;i++) dis[i] = 10000;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(0,s));
	for (int now;q.size();q.pop()) {
		now = q.top().first;

	}
}
int main() {
	freopen("luogu2149.in","r",stdin);
	freopen("luogu2149.out","w",stdout);
	scanf("%d%d%d%d%d%d",&n,&m,&s1,&t1,&s2,&t2);
	for (int i = 1,u,v,w;i <= m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	return 0;
}
