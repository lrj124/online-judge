//2021.07.13 14:42 by lrj124.
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,t,k,s,e,num[1001];
struct matrix {
	int a[201][201],n;
	inline void clear() { memset(a,0x3f,sizeof a); }
	inline matrix operator * (matrix x) const {
		matrix ans; ans.clear();
		ans.n = n;
		for (int k = 1;k <= n;k++)
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= n;j++) ans.a[i][j] = min(ans.a[i][j],a[i][k]+x.a[k][j]);
		return ans;
	}
} edge;
inline matrix power(matrix x,int y) {
	matrix ans; ans.clear(); ans.n = x.n;
	for (int i = 1;i <= n;i++) ans.a[i][i] = 0;
	for (;y;x = x*x,y >>= 1) if (y & 1) ans = ans*x;
	return ans;
}
int main() {
	edge.clear();
	for (scanf("%d%d%d%d",&k,&t,&s,&e);t--;) {
		int w,u,v;
		scanf("%d%d%d",&w,&u,&v);
		if (!num[u]) num[u] = ++n;
		if (!num[v]) num[v] = ++n;
		u = num[u]; v = num[v];
		edge.a[u][v] = edge.a[v][u] = w;
	}
	edge.n = n;
	printf("%d",power(edge,k).a[num[s]][num[e]]);
	return 0;
}
