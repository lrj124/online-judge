/************************************************
*Author        :  lrj124
*Created Time  :  2019.08.31.09:36
*Mail          :  1584634848@qq.com
*Problem       :  luogu4416
************************************************/
#include <cstdio>
#include <set>
const int maxn = 100000 + 10;
int n,q,top[maxn],col[maxn],map[maxn],dfn[maxn],dep[maxn],size[maxn],fa[maxn],son[maxn],fir[maxn],cnt,e;
struct Edge { int to,nex; } eg[maxn<<1];
std::set<int> ans[maxn];
inline void addedge(int u,int v) {
	eg[++e] = {v,fir[u]}; fir[u] = e;
	eg[++e] = {u,fir[v]}; fir[v] = e;
}
inline void dfs(int now,int f) {
	fa[now] = f;
	size[now] = 1;
	dep[now] = dep[f]+1;
	for (int i = fir[now];i;i = eg[i].nex)
		if (eg[i].to ^ f) {
			dfs(eg[i].to,now);
			size[now] += size[eg[i].to];
			if (size[eg[i].to] > size[son[now]]) son[now] = eg[i].to;
		}
}
inline void dfs2(int now,int ntop) {
	top[now] = ntop;
	dfn[++cnt] = now;
	map[now] = cnt;
	if (son[now]) dfs2(son[now],ntop);
	for (int i = fir[now];i;i = eg[i].nex)
		if (eg[i].to ^ fa[now] && eg[i].to ^ son[now]) dfs2(eg[i].to,eg[i].to);
}
int main() {
	freopen("luogu4416.in","r",stdin);
	freopen("luogu4416.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i = 1,u,v;i < n;i++,addedge(u,v)) scanf("%d%d",&u,&v);
	dfs(1,0);
	dfs2(1,1);
	for (int op,x,Ans;q--;) {
		scanf("%d%d",&op,&x); Ans = -1;
		if (!op) {
			col[x] ^= 1;
			if (col[x]) ans[top[x]].insert(map[x]);
			else ans[top[x]].erase(map[x]);
		} else {
			for (int tmp;x;x = fa[top[x]]) {
				tmp = *ans[top[x]].begin();
				if (ans[top[x]].size())
					if (dep[dfn[tmp]] <= dep[x]) Ans = dfn[tmp];
			}
			printf("%d\n",Ans);
		}
	}
	return 0;
}
