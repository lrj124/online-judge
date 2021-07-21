/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.09.21:37
*Mail          :  1584634848@qq.com
*Problem       :  luogu2055
************************************************/
#include <cstring>
#include <cstdio>
const int maxn = 50 + 10;
int T,n,a[maxn],b[maxn],c[maxn][maxn],match[maxn];
bool vis[maxn];
inline bool dfs(int now) {
	for (int i = 1;i <= n;i++)
		if (a[i] && c[now][i] && !vis[i]) {
			vis[i] = true;
			if (!match[i] || dfs(match[i])) {
				match[i] = now;
				return true;
			}
		}
	return false;
}
int main() {
	freopen("luogu2055.in","r",stdin);
	freopen("luogu2055.out","w",stdout);
	for (scanf("%d",&T);T--;memset(match,0,sizeof(match))) {
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		for (int i = 1;i <= n;i++) {
			scanf("%d",&b[i]);
			if (!a[i]) b[i] = 1;
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) scanf("%d",&c[i][j]);
			if (a[i]) c[i][i] = 1;
		}
		bool ans = true;
		for (int i = 1;i <= n;i++) {
			memset(vis,false,sizeof(vis));
			if ((!a[i] || !b[i]) && !dfs(i)) {
				ans = false;
				break;
			}
		}
		puts(ans ? "^_^" : "T_T");
	}
	return 0;
}
