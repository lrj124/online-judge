//I am hunting for the golden stag.
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
int n,col[maxn],cnt[2];
vector<int> edge[maxn];
inline void dfs(int now,int fa) {
	for (size_t i = 0;i < edge[now].size();i++) {
		int to = edge[now][i];
		if (to ^ fa) {
			if (col[to] ^ col[now]) cnt[col[to]]++;
			dfs(to,now);
		}
	}
}
int main() {
	freopen("cf734e.in","r",stdin);
	freopen("cf734e.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&col[i]);
	for (int i = 1,u,v;i < n;i++) {
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cnt[col[1]] = 1;
	dfs(1,0);
	printf("%d",min(cnt[0],cnt[1]));
	return 0;
}
