/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.23.10:31
*Mail          :  1584634848@qq.com
*Problem       :  luogu1265
************************************************/
#include <bits/stdc++.h>
using namespace std;
using pdi = pair<double,int>;
const int maxn = 5000 + 10;
priority_queue<pdi,vector<pdi>,greater<pdi> > q;
int n,x[maxn],y[maxn];
double ans,dis[maxn];
bool vis[maxn];
inline double calc(int a,int b) { return sqrt(1.*(x[a]-x[b])*(x[a]-x[b])+1.*(y[a]-y[b])*(y[a]-y[b])); }
inline void prim(int s) {
	for (int i = 1;i < maxn;i++) dis[i] = 1e9;
	q.push(make_pair(0,s));
	dis[s] = 0;
	while (q.size()) {
		int now = q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now] = true;
		ans += dis[now];
		for (int i = 1;i <= n;i++)
			if (dis[i] > calc(now,i)) {
				dis[i] = calc(now,i);
				q.push(make_pair(dis[i],i));
			}
	}
}
int main() {
	freopen("luogu1265.in","r",stdin);
	freopen("luogu1265.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&x[i],&y[i]);
	prim(1);
	printf("%.2lf",ans);
	return 0;
}
