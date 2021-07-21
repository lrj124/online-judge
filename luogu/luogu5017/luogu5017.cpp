//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
using namespace std;
using ll = long long;
const int maxn = 500 + 10;
const ll inf = 1e15;
ll ans(inf),f[maxn][maxn],pre[maxn];
int n,m,tot,t[maxn],sum[maxn];
int main() {
	freopen("luogu5017.in","r",stdin);
	freopen("luogu5017.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	t[0] = -9999999;
	for (int i = 1;i <= n;i++)
		if (t[i] == t[i-1]) {
			sum[tot]++;
			pre[tot] += t[i];
		} else {
			t[++tot] = t[i];
			sum[tot] = sum[tot-1]+1;
			pre[tot] = pre[tot-1]+t[i];
		}
	for (int i = 1;i <= tot;i++) for (int j = 0;j < m;j++) f[i][j] = inf;
	for (int i = 0;i < m;i++) f[1][i] = 0;
	for (int i = 2;i <= tot;i++)
		for (int k = 0;k < m;k++) {
			for (int j = 0;j < i;j++)
				if (t[i]+k-t[j]-m >= 0) f[i][k] = min(f[i][k],f[j][min(m-1,t[i]+k-t[j]-m)]+1ll*(t[i]+k)*(sum[i]-sum[j])-(pre[i]-pre[j]));
			if (k >= 1) f[i][k] = min(f[i][k],f[i][k-1]);
		}
	for (int i = 0;i < m;i++) ans = min(ans,f[tot][i]);
	printf("%lld",ans);
	return 0;
}
