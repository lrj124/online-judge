#include <utility>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 400 + 10;
int n,m,tot,pos[maxn][maxn];
pair<int,int> ans[820001];
bool fin[maxn];
inline void move(int x,int y) {
	ans[++tot] = make_pair(x,y);
	pos[y][++pos[y][0]] = pos[x][pos[x][0]--];
}
inline void solve(int l,int r) {
	if (l == r) return;
	int mid = l+r>>1;
	memset(fin,false,sizeof fin);
	for (int i = l;i <= mid;i++)
		for (int j = mid+1;j <= r;j++) if (!fin[i] && !fin[j]) {
			int s = 0,cnt = 0;
			for (int k = 1;k <= m;k++) s += (pos[i][k] <= mid)+(pos[j][k] <= mid);
			int a = (s >= m ? i : j),b = (s >= m ? j : i);
			for (int k = 1;k <= m;k++)
				if (s >= m) cnt += pos[a][k] <= mid;
				else cnt += pos[a][k] > mid;
			for (int k = 1;k <= cnt;k++) move(b,n+1);
			for (int k = m;k >= 1;k--)
				if (s >= m) move(a,pos[a][k] <= mid ? b : n+1);
				else move(a,pos[a][k] > mid ? b : n+1);
			for (int k = 1;k <= cnt;k++) move(b,a);
			for (int k = 1;k <= m-cnt;k++) move(n+1,a);
			for (int k = 1;k <= m-cnt;k++) move(b,n+1);
			for (int k = 1;k <= m-cnt;k++) move(a,b);
			for (int k = m;k >= 1;k--)
				if (s >= m) move(n+1,pos[a][0] < m && pos[n+1][k] <= mid ? a : b);
				else move(n+1,pos[a][0] < m && pos[n+1][k] > mid ? a : b);
			fin[a] = true;
		}
	solve(l,mid);
	solve(mid+1,r);
}
int main() {
	freopen("luogu7115.in","r",stdin);
	freopen("luogu7115.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) {
		pos[i][0] = m;
		for (int j = 1;j <= m;j++) scanf("%d",&pos[i][j]);
	}
	solve(1,n);
	printf("%d\n",tot);
	for (int i = 1;i <= tot;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
