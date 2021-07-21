/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.15.15:02
*Mail          :  1584634848@qq.com
*Problem       :  luogu5468
************************************************/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 200000 + 10;
int n,m,a,b,c,f[maxn],x[maxn],y[maxn],p[maxn],q[maxn],Max;
inline int calc(int x) { return a*x*x+b*x+c; }
vector<int> edge[maxn];
inline int dfs(int now) {
	if (!now || f[now]) return f[now];
	f[now] = 999999999;
	for (size_t i = 0;i < edge[x[now]].size();i++)
		if (q[edge[x[now]][i]] <= p[now]) f[now] = min(f[now],dfs(edge[x[now]][i])+calc(p[now]-q[edge[x[now]][i]]));
	return f[now];
}
int main() {
	freopen("luogu5468.in","r",stdin);
	freopen("luogu5468.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	for (int i = 1;i <= m;i++) {
		scanf("%d%d%d%d",&x[i],&y[i],&p[i],&q[i]);
		edge[y[i]].push_back(i);
	}
	edge[1].push_back(0);
	int ans = 999999999;
	for (int i = 0;i <= m;i++) if (y[i] == n) ans = min(ans,dfs(i)+q[i]);
	printf("%d",ans);
	return 0;
}
