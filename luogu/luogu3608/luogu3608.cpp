/************************************************
*Author        :  lrj124
*Created Time  :  2019.10.03.10:32
*Mail          :  1584634848@qq.com
*Problem       :  luogu3608
************************************************/
#include <algorithm>
#include <cstring>
#include <cstdio>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
#define lowbit(x) (x & -x)
const int maxn = 100000 + 10;
int n,tree[maxn],ans;
inline void add(int x) { for (;x <= n;x += lowbit(x)) tree[x]++; }
inline int que(int x) { int ans(0); for (;x;x -= lowbit(x)) ans += tree[x]; return ans; }
struct stu {
	int x,id;
	inline bool operator < (stu cmp) const {
		return x > cmp.x;
	}
} a[maxn];
int main() {
	freopen("luogu3608.in","r",stdin);
	freopen("luogu3608.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;a[i].id = i,i++) scanf("%d",&a[i].x);
	std :: sort(a+1,a+n+1); add(a[1].id);
	for (int i = 2,l,r;i <= n;i++) {
		l = que(a[i].id);
		r = i-l-1;
		ans += max(l,r) > min(l,r)<<1;
		add(a[i].id);
	}
	printf("%d",ans);
	return 0;
}
