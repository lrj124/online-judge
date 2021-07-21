//I am hunting for the golden stag.
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#define int long long
using namespace std;
map<pair<int,int>,bool> vis;
signed main() {
//	freopen("sqaure.in","r",stdin);
//	freopen("sqaure.out","w",stdout);
	int T,a[4];
	for (scanf("%lld",&T);T--;vis.clear()) {
		for (int i = 0;i < 4;i++) scanf("%lld",&a[i]);
		sort(a,a+4);
		int ans = 0;
		for (int i = 0;i < 4;i++)
			for (int j = 0;j < 4;j++) if (i ^ j)
				for (int ii = 0;ii < 4;ii++) if (ii ^ j && ii ^ i)
					for (int jj = 0;jj < 4;jj++) if (jj ^ i && jj ^ j && jj ^ ii)
						if (a[i]+a[ii] == a[j]+a[jj] && !vis[make_pair(a[i],a[j])]) {
							vis[make_pair(a[i],a[j])] = true;
							ans++;
						}
		printf("%lld\n",ans);
	}
	return 0;
}
