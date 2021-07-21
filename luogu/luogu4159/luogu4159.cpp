//2021.07.15 15:58 by lrj124.
#include <cstring>
#include <cstdio>
const int maxn = 10*9 + 10;
struct matrix {
	int n,a[maxn][maxn];
	inline void clear() { n = 0; memset(a,0,sizeof a); }
	inline matrix operator * (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				for (int k = 1;k <= n;k++) (ans.a[i][j] += a[i][k]*x.a[k][j]) %= 2009;
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
int n,t;
int main() {
	scanf("%d%d",&n,&t);
	adj.n = n*9;
	for (int i = 1;i <= n;i++) {
		for (int j = 2;j <= 9;j++) adj.a[(i-1)*9+j-1][(i-1)*9+j] = 1;
		for (int j = 1,x;j <= n;j++) {
			scanf("%1d",&x);
			if (x) adj.a[(i-1)*9+x][(j-1)*9+1] = 1;
		}
	}
	printf("%d",(adj^t).a[1][(n-1)*9+1]);
	return 0;
}
