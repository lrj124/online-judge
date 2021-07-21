/************************************************
*Author        :  lrj124
*Created Time  :  2020.10.26.15:47
*Problem       :  cf527d
************************************************/
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int n,ans,las(-1000000000);
struct seg {
	int l,r;
	inline bool operator < (seg cmp) const {
		return r < cmp.r || (r == cmp.r && l > cmp.l);
	}
} a[maxn];
int main() {
	freopen("cf527d.in","r",stdin);
	freopen("cf527d.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1,x,w;i <= n;i++) {
		scanf("%d%d",&x,&w);
		a[i] = { x-w,x+w };
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++)
		if (a[i].l >= las) {
			las = a[i].r;
			ans++;
		}
	printf("%d",ans);
	return 0;
}
