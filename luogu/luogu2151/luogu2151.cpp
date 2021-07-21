//2021.07.16 11:56 by lrj124.
#include <utility>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 120 + 10;
const int mod = 45989;
pair<int,int> road[maxn];
int n,m,t,s,e;
struct matrix {
	int n,a[maxn][maxn];
	inline void clear() { n = 0; memset(a,0,sizeof a); }
	inline matrix operator * (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				for (int k = 1;k <= n;k++) (ans.a[i][j] += a[i][k]*x.a[k][j]) %= mod;
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
int main() {
	scanf("%d%d%d%d%d",&n,&m,&t,&s,&e);
	for (int i = 1,u,v;i <= m;i++) {
		scanf("%d%d",&u,&v);
		road[i<<1] = make_pair(u,v);
		road[i<<1|1] = make_pair(v,u);
	}
	adj.n = (m+1)<<1;
	for (int i = 2;i <= (m<<1|1);i++) {
		if (road[i].first == s) adj.a[1][i] = 1;
		if (road[i].second == e) adj.a[i][(m+1)<<1] = 1;
		for (int j = 2;j <= (m<<1|1);j++)
			if (i^j^1 && road[i].second == road[j].first) adj.a[i][j] = 1;
	}
	printf("%d",(adj^(t+1)).a[1][(m+1)<<1]);
	return 0;
}
