//I am hunting for the golden stag.
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 2e5 + 10;
int n,val,cnt,ans,a[maxn],b[maxn],c[maxn],d[maxn],f[maxn],p[maxn],siz[maxn];
map<int,int> vis;
inline int find(int x) { return f[x] = (f[x] == x ? x : find(f[x])); }
inline int ash(int x) { return lower_bound(p+1,p+p[0]+1,x)-p; }
inline void uni(int x,int y) { x = find(x),y = find(y); f[x] = y; siz[x] += siz[y]; }
int main() {
	freopen("agc016d.in","r",stdin);
	freopen("agc016d.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]),val ^= a[i],vis[a[i]]++;
	for (int i = 1;i <= n;i++) scanf("%d",&b[i]),vis[b[i]]--;
	vis[val]++; for (int i = 1;i <= n;i++) if (vis[b[i]] < 0) return printf("-1")*0;
	for (int i = 1;i <= n;i++) { p[++p[0]] = a[i]; p[++p[0]] = b[i]; }
	p[++p[0]] = val;
	sort(p+1,p+p[0]+1);
	p[0] = unique(p+1,p+p[0]+1)-(p+1);
	for (int i = 1;i <= p[0];i++) { f[i] = i; siz[i] = 1; }
	for (int i = 1;i <= n;i++)
		if (a[i] ^ b[i]) { ans++; uni(ash(a[i]),ash(b[i])); }
	if (ans == 0) return printf("0")*0;
	for (int i = 1;i <= p[0];i++) if (find(i) == i && siz[i] ^ 1) ans++;
	if (siz[find(ash(val))] ^ 1) ans--;
	printf("%d",ans);
	return 0;
}
