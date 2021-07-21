/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.22.16:18
*Mail          :  1584634848@qq.com
*Problem       :  luogu1502
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 10000 + 10;
int T,n,w,h,cnt,rt,Max,ans;
struct scan {
	int x,l,r,w,d;
	inline bool operator < (scan cmp) const {
		return x < cmp.x || (x == cmp.x && d > cmp.d);
	}
} line[maxn<<3];
struct seg { int l,r,maxv,mark; } tree[5000010];
inline void pushup(int root) { tree[root].maxv = max(tree[tree[root].l].maxv,tree[tree[root].r].maxv); }
inline void pushdown(int root) {
	if (tree[root].mark) {
		if (!tree[root].l) tree[root].l = ++cnt;
		if (!tree[root].r) tree[root].r = ++cnt;
		tree[tree[root].l].maxv += tree[root].mark;
		tree[tree[root].r].maxv += tree[root].mark;
		tree[tree[root].l].mark += tree[root].mark;
		tree[tree[root].r].mark += tree[root].mark;
		tree[root].mark = 0;
	}
}
inline void update(int l,int r,int ul,int ur,int& root,int x) {
	if (r < ul || l > ur) return;
	if (!root) root = ++cnt;
	if (ul <= l && r <= ur) {
		tree[root].maxv += x;
		tree[root].mark += x;
		return;
	}
	pushdown(root);
	int mid = l+r>>1;
	update(l,mid,ul,ur,tree[root].l,x);
	update(mid+1,r,ul,ur,tree[root].r,x);
	pushup(root);
}
int main() {
	freopen("luogu1502.in","r",stdin);
	freopen("luogu1502.out","w",stdout);
	for (scanf("%d",&T);T--;ans = 0) {
		memset(tree,0,sizeof(tree));
		scanf("%d%d%d",&n,&w,&h);
		for (int i = 1,x,y,z;i <= n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			Max = max(Max,x+w+1);
			line[i<<1] = {x+w-1,y,y+h-1,z,-1};
			line[(i<<1)-1] = {x,y,y+h-1,z,1};
		}
		sort(line+1,line+(n<<1|1));
		for (int i = 1;i <= (n<<1);i++) {
			update(1,Max,line[i].l,line[i].r,rt,line[i].w*line[i].d);
			ans = max(ans,tree[rt].maxv);
		}
		printf("%d\n",ans);
	}
	return 0;
}
