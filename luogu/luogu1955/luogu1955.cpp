/************************************************
*Author        :  lrj124
*Created Time  :  2019.11.06.16:33
*Mail          :  1584634848@qq.com
*Problem       :  luogu1955
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1000000 + 10;
int t,n,fa[maxn],p[maxn];
struct op {
	int x,y,e;
	inline bool operator < (op cmp) const {
		return e > cmp.e;
	}
} a[maxn];
bool ans;
inline int find(int x) { return fa[x] = (fa[x] == x ? x : find(fa[x])); }
inline void uni(int x,int y) { x = find(x); y = find(y); fa[x] = y; }
int main() {
	freopen("luogu1955.in","r",stdin);
	freopen("luogu1955.out","w",stdout);
	for (scanf("%d",&t);t--;ans = false,p[0] = 0) {
		scanf("%d",&n);
		for (int i = 1;i <= n<<2;i++) fa[i] = i;
		for (int i = 1,x,y,z;i <= n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			a[i] = { x,y,z };
			p[++p[0]] = x;
			p[++p[0]] = y;
		}
		sort(p+1,p+p[0]+1);
		p[0] = unique(p+1,p+p[0]+1)-p;
		for (int i = 1;i <= n;i++) {
			a[i].x = lower_bound(p+1,p+p[0]+1,a[i].x)-p;
			a[i].y = lower_bound(p+1,p+p[0]+1,a[i].y)-p;
		}
		sort(a+1,a+n+1);
		for (int i = 1;i <= n;i++) {
			a[i].x = find(a[i].x);
			a[i].y = find(a[i].y);
			if (a[i].e) fa[a[i].x] = a[i].y;
			else if (a[i].x == a[i].y) ans = true;
		}
		puts(ans ? "NO" : "YES");
	}
	return 0;
}
