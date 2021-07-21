//I am hunting for the golden stag.
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
using pii = pair<long long,long long>;
const int maxn = 2e5 + 10;
int n,q,s,node,rt_in,rt_out,rs[maxn<<2],ls[maxn<<2];
vector<pii> edge[maxn<<2];
long long dis[maxn<<2];
bool vis[maxn<<2];
inline void build_in(int l,int r,int& root) {
	if (l == r) return void(root = l);
	root = ++node;
	int mid = l+r>>1;
	build_in(l,mid,ls[root]);
	build_in(mid+1,r,rs[root]);
	edge[ls[root]].push_back(make_pair(root,0));
	edge[rs[root]].push_back(make_pair(root,0));
}
inline void build_out(int l,int r,int& root) {
	if (l == r) return void(root = l);
	root = ++node;
	int mid = l+r>>1;
	build_out(l,mid,ls[root]);
	build_out(mid+1,r,rs[root]);
	edge[root].push_back(make_pair(ls[root],0));
	edge[root].push_back(make_pair(rs[root],0));
}
inline void update_in(int l,int r,int u,int vl,int vr,int root,int w) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[root].push_back(make_pair(u,w)));
	int mid = l+r>>1;
	update_in(l,mid,u,vl,vr,ls[root],w);
	update_in(mid+1,r,u,vl,vr,rs[root],w);
}
inline void update_out(int l,int r,int u,int vl,int vr,int root,int w) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[u].push_back(make_pair(root,w)));
	int mid = l+r>>1;
	update_out(l,mid,u,vl,vr,ls[root],w);
	update_out(mid+1,r,u,vl,vr,rs[root],w);
}
inline void dijkstra() {
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for (q.push(make_pair(0,s)),fill(dis+1,dis+n*4+1,1e15),dis[s] = 0;q.size();) {
		int now = q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now] = true;
		for (size_t i = 0;i < edge[now].size();i++) {
			int to = edge[now][i].first,w = edge[now][i].second;
			if (dis[to] > dis[now]+w) {
				dis[to] = dis[now]+w;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int main() {
	freopen("cf786b.in","r",stdin);
	freopen("cf786b.out","w",stdout);
	scanf("%d%d%d",&n,&q,&s); node = n;
	for (build_in(1,n,rt_in),build_out(1,n,rt_out);q--;) {
		int op,v,l,r,w; scanf("%d",&op);
		if (op == 1) {
			scanf("%d%d%d",&l,&r,&w);
			edge[l].push_back(make_pair(r,w));
		}
		if (op == 2) {
			scanf("%d%d%d%d",&v,&l,&r,&w);
			update_out(1,n,v,l,r,rt_out,w);
		}
		if (op == 3) {
			scanf("%d%d%d%d",&v,&l,&r,&w);
			update_in(1,n,v,l,r,rt_in,w);
		}
	}
	dijkstra();
	for (int i = 1;i <= n;i++) printf("%lld ",dis[i] == 1e15 ? -1 : dis[i]);
	return 0;
}
