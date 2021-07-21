#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,q,t[maxn],a[maxn],m[maxn],b[maxn];
vector<int> e[maxn];
inline bool cmp(int x,int y) { return a[x] > a[y]; }
inline void ins(int x) { for (;x <= n;x += x&-x) t[x]++; }
inline int que(int x) { int c = 0; for (;x;x -= x&-x) c += t[x]; return c; }
inline void dfs(int o) {
	int t = que(a[o]);
	for (size_t i = 0;i < e[o].size();i++) dfs(e[o][i]);
	b[o] = que(a[o])-t; ins(a[o]);
}
int main() {
	scanf("%d",&n);
	for (int i = 1;i <= n;m[i] = i,i++) scanf("%d",&a[i]);
	sort(m+1,m+n+1,cmp); for (int i = 1;i <= n;i++) a[m[i]] = i;
	for (int i = 2,x;i <= n;e[x].push_back(i),i++) scanf("%d",&x);
	dfs(1); for (int i = 1;i <= n;i++) printf("%d\n",b[i]);
	return 0;
}
