//I am hunting for the golden stag.
#include <cstring>
#include <cstdio>
const int maxn = (1<<10) + 10;
int t,d,a[11],cnt[11],fac[11] = { 1 };
long long f[maxn][1001];
int main() {
	freopen("luogu4163.in","r",stdin);
	freopen("luogu4163.out","w",stdout);
	for (int i = 1;i <= 10;i++) fac[i] = fac[i-1]*i;
	for (scanf("%d",&t);t--;memset(cnt,0,sizeof cnt),memset(f,0,sizeof f)) {
		char str[11]; f[0][0] = 1;
		scanf("%s %d",str+1,&d);
		int n = strlen(str+1);
		for (int i = 1;i <= n;i++) { a[i] = str[i]-'0'; cnt[a[i]]++; }
		for (int s = 0;s < (1<<n);s++)
			for (int j = 0;j < d;j++)
				for (int k = 1;k <= n;k++)
					if (!(s>>(k-1)&1)) f[s|(1<<(k-1))][(10*j+a[k])%d] += f[s][j];
		for (int i = 0;i <= 9;i++) f[(1<<n)-1][0] /= fac[cnt[i]];
		printf("%lld\n",f[(1<<n)-1][0]);
	}
	return 0;
}
