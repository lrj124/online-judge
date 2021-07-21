/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.18.11:32
*Mail          :  1584634848@qq.com
*Problem       :  luogu1341
************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
int n,deg[maxn],ans[maxn],s,cnt;
bool eg[maxn][maxn];
char x,y;
inline void dfs(int now) {
	for (int i = 0;i < maxn;i++)
		if (eg[now][i]) { eg[now][i] = eg[i][now] = false; dfs(i); }
	ans[++ans[0]] = now;
}
int main() {
	freopen("luogu1341.in","r",stdin);
	freopen("luogu1341.out","w",stdout);
	for (scanf("%d",&n);n--;) {
		scanf("\n%c%c",&x,&y);
		deg[1*x]++; deg[1*y]++;
		eg[1*x][1*y] = eg[1*y][1*x] = true;
	}
	for (int i = 0;i < maxn;i++) {
		if (deg[i]&1) cnt++;
		if (deg[i]&1 && !s) s = i;
	}
	if (!s) for (int i = 0;i < maxn;i++) if (deg[i]) { s = i; break; }
	if (cnt && cnt ^ 2) { printf("No Solution"); return 0; }
	dfs(s);
	for (int i = ans[0];i >= 1;i--) printf("%c",ans[i]);
	return 0;
}
