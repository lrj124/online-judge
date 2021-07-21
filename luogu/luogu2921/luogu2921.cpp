/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.19.11:24
*Mail          :  1584634848@qq.com
*Problem       :  luogu2921
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n,nex[maxn],ans[maxn],deg[maxn];
bool vis[maxn];
inline void delet(int now) {
	vis[now] = true;
	deg[nex[now]]--;
	if (!deg[nex[now]]) delet(nex[now]);
}
inline int dfs(int now,int tot) {
	ans[now] = tot;
	if (ans[nex[now]]) return tot;
	return ans[now] = dfs(nex[now],tot+1);
}
inline int solve(int now) {
	if (ans[now]) return ans[now];
	return ans[now] = solve(nex[now])+1;
}
int main() {
	freopen("luogu2921.in","r",stdin);
	freopen("luogu2921.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&nex[i]),deg[nex[i]]++;
	for (int i = 1;i <= n;i++) if (!deg[i] && !vis[i]) delet(i);
	for (int i = 1;i <= n;i++) if (deg[i] && !ans[i]) dfs(i,1);
	for (int i = 1;i <= n;i++) if (!deg[i] && !ans[i]) solve(i);
	for (int i = 1;i <= n;i++) printf("%d\n",ans[i]);
	return 0;
}
