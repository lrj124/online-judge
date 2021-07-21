//I am hunting for the golden stag.
#include <cstdio>
using ll = long long;
const int maxn = 4e4 + 10;
int n,ch[maxn][2],dep[maxn];
ll f[maxn][41][41];
inline ll dfs(int now) {
	dep[now] = dep[fa]+1;
	if (!now) return;
	dfs(ch[now][0]);
	dfs(ch[now][1]);
}
int main() {
	freopen("luogu4438.in","r",stdin);
	freopen("luogu4438.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		ch[i][0] = u+(u > 0 ? n : -u-u);
		ch[i][1] = v+(v > 0 ? n : -v-v);
	}
	dfs(1);
	return 0;
}
