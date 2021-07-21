#include <functional>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 50000 + 10;
typedef pair<int,int> pii;
pair<pii,int> per[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
int n,tot,ans[maxn];
int main() {
	freopen("luogu2859.in","r",stdin);
	freopen("luogu2859.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) {
		scanf("%d%d",&per[i].first.first,&per[i].first.second);
		per[i].second = i;
	}
	sort(per+1,per+n+1);
	q.push(make_pair(per[1].first.second,ans[per[1].second] = ++tot));
	for (int i = 2;i <= n;i++) {
		int now = q.top().first,num = q.top().second;
		if (now < per[i].first.first) {
			q.push(make_pair(per[i].first.second,ans[per[i].second] = num));
			q.pop();
		} else q.push(make_pair(per[i].first.second,ans[per[i].second] = ++tot));
	}
	printf("%d\n",tot);
	for (int i = 1;i <= n;i++) printf("%d\n",ans[i]);
	return 0;
}
