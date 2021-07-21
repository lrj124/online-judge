//I am hunting for the golden stag.
#include <algorithm>
#include <vector>
#include <cstdio>
#include <stack>
#define opp(x) (x+cnt)
using namespace std;
const int maxn = 1e5 + 10;
int n,node,tot,cnt,scccnt,rt_in,rt_out,x[maxn],y[maxn],scc[maxn<<4],low[maxn<<4],dfn[maxn<<4],ls[maxn<<4],rs[maxn<<4];
pair<int,int> p[maxn];
stack<int> s; bool vis[maxn<<4];
vector<int> edge[maxn<<4];
inline void build_in(int l,int r,int& root) {
	if (l == r) return void(root = l);
	root = ++node;
	int mid = l+r>>1;
	build_in(l,mid,ls[root]);
	build_in(mid+1,r,rs[root]);
	edge[ls[root]].push_back(root);
	edge[rs[root]].push_back(root);
}
inline void build_out(int l,int r,int& root) {
	if (l == r) return void(root = l);
	root = ++node;
	int mid = l+r>>1;
	build_out(l,mid,ls[root]);
	build_out(mid+1,r,rs[root]);
	edge[root].push_back(ls[root]);
	edge[root].push_back(rs[root]);
}
inline void update_in(int l,int r,int u,int vl,int vr,int root) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[root].push_back(u));
	int mid = l+r>>1;
	update_in(l,mid,u,vl,vr,ls[root]);
	update_in(mid+1,r,u,vl,vr,rs[root]);
}
inline void update_out(int l,int r,int u,int vl,int vr,int root) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[u].push_back(root));
	int mid = l+r>>1;
	update_out(l,mid,u,vl,vr,ls[root]);
	update_out(mid+1,r,u,vl,vr,rs[root]);
}
inline void tarjan(int now) {
	dfn[now] = low[now] = ++tot;
	s.push(now); vis[now] = true;
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (!dfn[to]) {
			tarjan(to);
			low[now] = min(low[now],low[to]);
		} else if (vis[to]) low[now] = min(low[now],dfn[to]);
	}
	if (low[now] == dfn[now]) {
		for (scccnt++;s.top() ^ now;vis[s.top()] = false,s.pop()) scc[s.top()] = scccnt;
		scc[s.top()] = scccnt;
		vis[s.top()] = false,s.pop();
	}
}
inline bool check(int mid) {
	for (int i = 1;i <= cnt*16;i++) { dfn[i] = low[i] = scc[i] = vis[i] = 0; edge[i].clear(); }
	for (int i = 1;i <= cnt*16;i++) ls[i] = rs[i] = 0;
	for (;s.size();s.pop());
	tot = scccnt = 0; node = cnt+cnt;
	build_in(1,cnt+cnt,rt_in);
	build_out(1,cnt+cnt,rt_out);
	for (int i = 1,u,v;i <= n;i++) {
		u = lower_bound(p+1,p+cnt+1,make_pair(x[i],i))-p;
		v = lower_bound(p+1,p+cnt+1,make_pair(y[i],i+n))-p;
		if (u ^ v) {
			edge[u].push_back(opp(v));
			edge[v].push_back(opp(u));
			edge[opp(u)].push_back(v);
			edge[opp(v)].push_back(u);
		}
	}
	for (int i = 1,u,v;i <= cnt;i++) {
		u = upper_bound(p+1,p+cnt+1,make_pair(p[i].first-mid,999999999))-p;
		v = upper_bound(p+1,p+cnt+1,make_pair(p[i].first+mid-1,0))-p-1;
		if (u < i) {
			update_in(1,cnt+cnt,opp(i),u,i-1,rt_in);
			update_out(1,cnt+cnt,i,opp(u),opp(i-1),rt_out);
		}
		if (v > i) {
			update_in(1,cnt+cnt,opp(i),i+1,v,rt_in);
			update_out(1,cnt+cnt,i,opp(i+1),opp(v),rt_out);
		}
	}
	for (int i = 1;i <= cnt+cnt;i++) if (!dfn[i]) tarjan(i);
	for (int i = 1;i <= cnt;i++) if (scc[i] == scc[opp(i)]) return false;
	return true;
}
inline int solve() {
	int l(0),r(1e9),mid,ans(0);
	for (;l <= r;check(mid = l+r>>1) ? ans = mid,l = mid+1 : r = mid-1);
	return ans;
}
int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		p[i] = make_pair(x[i],i); p[i+n] = make_pair(y[i],i+n);
	}
	cnt = n+n;
	sort(p+1,p+n+n+1);
	printf("%d",solve());
	return 0;
}
