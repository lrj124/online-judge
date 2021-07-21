/************************************************
*Author        :  lrj124
*Created Time  :  2019.09.20.22:04
*Mail          :  1584634848@qq.com
*Problem       :  cf612d
************************************************/
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<pair<int,int> > v;
vector<int> ans;
int n,k,cnt;
int main() {
	freopen("cf612d.in","r",stdin);
	freopen("cf612d.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1,x,y;i <= n;i++) {
		scanf("%d%d",&x,&y);
		v.push_back(make_pair(x,0));
		v.push_back(make_pair(y,1));
	}
	sort(v.begin(),v.end());
	for (size_t i = 0;i < v.size();i++)
		if (v[i].second) {
			if (cnt-- == k) ans.push_back(v[i].first);
		} else if (++cnt == k) ans.push_back(v[i].first);
	printf("%d\n",ans.size()/2);
	for (size_t i = 0;i < ans.size()/2;i++) printf("%d %d\n",ans[i*2],ans[i*2+1]);
	return 0;
}
