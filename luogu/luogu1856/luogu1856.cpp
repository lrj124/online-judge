//I am hunting for the golden stag.
#include <cstdio>
const int maxn = 1e4 + 10;
int n,cnt[maxn<<3],len[maxn<<3],sum[maxn<<3];
struct linehor {
	int x1,x2,y,k;
	inline bool operator < (linehor cmp) const {
		return y < cmp.y;
	}
} lih;
struct linever {
	int y1,y2,x,k;
	inline bool operator < (linever cmp) const {
		return x < cmp.x;
	}
} liv;
inline void update(int l,int r,int ul,int ur,int root,int x) {
	if (l > ur || r < ul) return;
	if (ul <= l && r <= ur) {
		
		return;
	}
}
int main() {
	freopen("luogu1856.in","r",stdin);
	freopen("luogu1856.out","w",stdout);
	scanf("");
	return 0;
}
