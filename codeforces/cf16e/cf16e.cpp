//I am hunting for the golden stag.
#include <cstdio>
const int maxn = 18 + 1;
double a[maxn][maxn],f[1<<maxn];
int n;
inline int count(int x) {
	int ans = 0;
	for (int i = 1;i <= n;i++) if (!((x>>(i-1))&1)) ans++;
	return ans;
}
int main() {
	freopen("cf16e.in","r",stdin);
	freopen("cf16e.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) scanf("%lf",&a[i][j]);
	f[0] = 1;
	for (int s = 0;s < (1<<n);s++)
		for (int i = 1;i <= n;i++) if (!((s>>(i-1))&1))
			for (int j = 1;j <= n;j++) if (!((s>>(j-1))&1) && i ^ j) {
				int tos = s|(1<<(i-1)),num = count(s);
				f[tos] += f[s]*a[j][i]/(num*(num-1)/2.);
			}
	for (int i = 1;i <= n;i++) printf("%f ",f[((1<<n)-1)^(1<<(i-1))]);
	return 0;
}
