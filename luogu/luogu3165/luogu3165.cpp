#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,m,num,root,father[maxn],ch[maxn][2],key[maxn],size[maxn];
bool mark[maxn];
inline bool getfa(int x) { return ch[father[x]][1] == x; }
inline void pushup(int x) { size[x] = size[ch[x][0]]+size[ch[x][1]]+1; }
inline void pushdown(int x) {
	if (mark[x]) {
		if (ch[x][0]) mark[ch[x][0]] ^= 1;
		if (ch[x][1]) mark[ch[x][1]] ^= 1;
		swap(ch[x][0],ch[x][1]);
		mark[x] ^= 1;
	}
}
inline void rotate(int x) {
	int old = father[x],oldfa = father[father[x]],w = getfa(x);
	pushdown(old);
	pushdown(x);
	ch[old][w] = ch[x][w^1]; father[ch[old][w]] = old;
	ch[x][w^1] = old; father[old] = x;
	father[x] = oldfa;
	if (oldfa) ch[oldfa][ch[oldfa][1] == old] = x;
	pushup(old);
	pushup(x);
}
inline void splay(int x,int rt) {
	for (int fa = father[x];(fa = father[x]) ^ rt;rotate(x)) {
		pushdown(father[fa]);
		pushdown(fa);
		pushdown(x);
		if (father[fa] ^ rt) rotate(getfa(fa) == getfa(x) ? fa : x);
	}
	if (!rt) root = x;
}
inline int find(int x) {
	int now = root;
	while (true) {
		pushdown(now);
		if (ch[now][0] && x <= size[ch[now][0]]) now = ch[now][0];
		else {
			x -= size[ch[now][0]]+1;
			if (x <= 0) return now;
			now = ch[now][1];
		}
	}
}
inline void split(int l,int r) {
	int x = find(l),y = find(r+2);
	splay(x,0);
	splay(y,x);
	mark[ch[y][0]] ^= 1;
}
inline void build(int l,int r,int rt) {
	if (l > r) return;
	int mid = l+r>>1;
	build(l,mid-1,mid);
	build(mid+1,r,mid);
	father[mid] = rt;
	key[mid] = mid-1;
	pushup(mid);
	ch[rt][mid >= rt] = mid;
}
struct Val {
	int num,id;
	inline bool operator < (const Val cmp) const {
		return num < cmp.num || (num == cmp.num && id < cmp.id);
	}
} a[maxn];
int main() {
	freopen("luogu3165.in","r",stdin);
	freopen("luogu3165.out","w",stdout);
	scanf("%d",&n);
	for (int i = 2;i <= n+1;i++) {
		scanf("%d",&a[i].num);
		a[i].id = i;
	}
	a[1].id = 1; a[1].num = -9999999;
	a[n+2].id = n+2; a[n+2].num = 9999999;
	sort(a+1,a+n+3);
	build(1,n+2,0);
	root = n+3>>1;
	for (int i = 2;i <= n;i++) {
		splay(a[i].id,0);
		printf("%d ",size[ch[root][0]]);
		split(i-1,size[ch[root][0]]);
	}
	printf("%d",n);
	return 0;
}
