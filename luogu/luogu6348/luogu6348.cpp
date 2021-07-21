//I am hunting for the golden stag.
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
using pii = pair<int,int>;
const int maxn = 4e6 + 10;
int n,m,s,node,in,out,ls[maxn],rs[maxn],dis[maxn];
vector<pii> edge[maxn<<1];
bool vis[maxn];
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
inline void update_in(int l,int r,int u,int vl,int vr,int root) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[root].push_back(make_pair(u,0)));
	int mid = l+r>>1;
	update_in(l,mid,u,vl,vr,ls[root]);
	update_in(mid+1,r,u,vl,vr,rs[root]);
}
inline void update_out(int l,int r,int u,int vl,int vr,int root) {
	if (l > vr || r < vl) return;
	if (vl <= l && r <= vr) return void(edge[u].push_back(make_pair(root,0)));
	int mid = l+r>>1;
	update_out(l,mid,u,vl,vr,ls[root]);
	update_out(mid+1,r,u,vl,vr,rs[root]);
}
inline void dijkstra() {
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for (fill(dis+1,dis+node+1,999999999),q.push(make_pair(0,s)),dis[s] = 0;q.size();) {
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
	freopen("luogu6348.in","r",stdin);
	freopen("luogu6348.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	node = n;
	build_in(1,n,in);
	build_out(1,n,out);
	for (int i = 1,la,ra,lb,rb;i <= m;i++) {
		scanf("%d%d%d%d",&la,&ra,&lb,&rb);
		update_in(1,n,++node,la,ra,in);
		edge[node].push_back(make_pair(node+1,1));
		update_out(1,n,++node,lb,rb,out);

		update_in(1,n,++node,lb,rb,in);
		edge[node].push_back(make_pair(node+1,1));
		update_out(1,n,++node,la,ra,out);
	}
	dijkstra();
	for (int i = 1;i <= n;i++) printf("%d\n",dis[i]);
	return 0;
}
