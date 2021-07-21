//2021.07.20 09:22 by lrj124.
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 10;
int t,n,ans,a[maxn],b[maxn];
bool v[maxn],vis[maxn];
int main() {
	for (scanf("%d",&t);t--;fill(vis+1,vis+n+1,false),fill(v+1,v+n+1,false)) {
		scanf("%d",&n); ans = 0;
		for (int i = 1;i <= n;i++) {
			scanf("%d",&a[i]);
			vis[a[i]] = true;
		}
		int num = n;
		for (int i = 1;i <= n;i++)
			if (!v[a[i]]) v[b[i] = a[i]] = (bool)++ans;
			else {
				for (;vis[num];num--);
				vis[b[i] = num] = true;
			}
		printf("%d\n",ans);
		for (int i = 1;i <= n;i++) printf("%d%c",b[i],i ^ n ? ' ' : '\n');
	}
	return 0;
}
