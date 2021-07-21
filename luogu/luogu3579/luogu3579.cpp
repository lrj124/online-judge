//I am hunting for the golden stag.
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t,a,b,c,d,ans;
int main() {
	freopen("luogu3579.in","r",stdin);
	freopen("luogu3579.out","w",stdout);
	for (scanf("%d",&t);t--;ans = 0) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for (int i = 1,j;i <= min(b,d);i = j+1) {
			j = min(b/(b/i),d/(d/i));
			if (b/j > (a-1)/j && d/j > (c-1)/j) ans = max(ans,j);
		}
		printf("%d\n",ans);
	}
	return 0;
}
