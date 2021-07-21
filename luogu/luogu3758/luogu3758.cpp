//2021.07.16 10:36 by lrj124.
#include <cstring>
#include <cstdio>
const int maxn = 30 + 10;
struct matrix {
	int n,a[maxn][maxn];
	inline void clear() { n = 0; memset(a,0,sizeof a); }
	inline matrix operator * (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				for (int k = 1;k <= n;k++) (ans.a[i][j] += a[i][k]*x.a[k][j]) %= 2017;
		return ans;
	}
	inline matrix operator ^ (int y) const {
		matrix x = *this,ans; ans.clear();
		ans.n = n;
		for (int i = 1;i <= n;i++) ans.a[i][i] = 1;
		for (;y;y >>= 1,x = x*x) if (y & 1) ans = ans*x;
		return ans;
	}
} adj;
int n,m,t,ans;
int main() {
	scanf("%d%d",&n,&m);
	adj.n = n+1;
	for (int i = 1;i <= n+1;i++) {
		adj.a[i][i] = 1;
		adj.a[i][n+1] = 1;
	}
	for (int u,v;m--;) {
		scanf("%d%d",&u,&v);
		adj.a[u][v] = adj.a[v][u] = 1;
	}
	scanf("%d",&t);
	matrix res = adj^t;
	for (int i = 1;i <= n+1;i++) (ans += res.a[1][i]) %= 2017;
	printf("%d",ans);
	return 0;
}
