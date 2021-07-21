/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.05.21:36
*Mail          :  1584634848@qq.com
*Problem       :  luogu4645
************************************************/
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 10000 + 10;
const int mod = 1e9;
vector<int> edge[maxn],eg[maxn];
int n,m,deg[maxn],cnt;
bool loop,vis[maxn];
long long f[maxn];
long long dfs(int now) {
	if (f[now] ^ -1) return f[now];
	vis[now] = 1;
	long long sum = 0;
	for (size_t i = 0;i < edge[now].size();i++) {
		if (!vis[edge[now][i]]) sum += dfs(edge[now][i]);
		if (sum > mod) sum %= mod;
	}
	vis[now] = 0;
	return f[now] = sum;
}
int main() {
 	freopen("luogu4645.in","r",stdin);
 	freopen("luogu4645.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&m);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v); deg[v]++;
		edge[u].push_back(v);
		eg[u].push_back(v);
		eg[v].push_back(u);
	}
	f[2] = 1;
	printf("%lld",dfs(1));
	return 0;
}
