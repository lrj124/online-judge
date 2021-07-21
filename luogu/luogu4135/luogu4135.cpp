#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1e5 + 10;
const int N = 400 + 10;
int n,c,m,x,y,las,block,answer,tot,a[maxn],cnt[maxn],pre[N][maxn],ans[N][N],fea[N],clo[maxn];
inline void add(int k) {
	cnt[k]++;
	if (!((pre[y][k]-pre[x-1][k]+cnt[k])&1)) answer++;
	else if ((pre[y][k]-pre[x-1][k]+cnt[k]) ^ 1) answer--;
}
inline void del(int k) {
	cnt[k]--;
	if (!((pre[y][k]-pre[x-1][k]+cnt[k])&1) && pre[y][k]-pre[x-1][k]+cnt[k]) answer++;
	else if (pre[y][k]-pre[x-1][k]+cnt[k]) answer--;
}
int main() {
	freopen("luogu4135.in","r",stdin);
	freopen("luogu4135.out","w",stdout);
	scanf("%d%d%d",&n,&c,&m); block = (int)pow(n,0.5);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i += block) {
		fea[++tot] = i;
		for (int j = i;j <= min(i+block-1,n);j++) clo[j] = tot;
	}
	int tmp = 1;
	for (int i = 1;i <= n;i++) {
		cnt[a[i]]++;
		if (i == min(fea[tmp]+block-1,n)) {
			for (int j = 1;j <= n;j++) pre[tmp][j] = cnt[j];
			tmp++;
		}
	}
	for (int i = 1;i <= tot;i++) {
		memset(cnt,0,sizeof cnt);
		answer = 0;
		tmp = i;
		for (int j = fea[i];j <= n;j++) {
			cnt[a[j]]++;
			if (!(cnt[a[j]]&1)) answer++;
			else if (cnt[a[j]] ^ 1) answer--;
			if (j == min(fea[tmp]+block-1,n)) ans[i][tmp++] = answer;
		}
	}
	memset(cnt,0,sizeof cnt);
	for (int l,r;m--;) {
		scanf("%d%d",&l,&r);
		l = (l+las)%n+1;
		r = (r+las)%n+1;
		if (l > r) swap(l,r);
		x = clo[l]; y = clo[r];
		int L = fea[x],R = min(fea[y]+block-1,n);
		answer = ans[x][y];
		for (;L < l;del(a[L++]));
		for (;L > l;add(a[--L]));
		for (;R < r;add(a[++R]));
		for (;R > r;del(a[R--]));
		printf("%d\n",las = answer);
		L = fea[x]; R = min(fea[y]+block-1,n);
		for (;L < l;add(a[L++]));
		for (;L > l;del(a[--L]));
		for (;R < r;del(a[++R]));
		for (;R > r;add(a[R--]));
	}
	return 0;
}
